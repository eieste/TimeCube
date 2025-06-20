<script lang="ts">
	import config from '$config';
	import type { WiFiNetwork } from '$lib/types';
	import type { PageProps, PageLoad } from './$types';
	import { page } from '$app/state';
	import { WifiIcon } from 'svelte-feather-icons';
	import { ListItem, List } from '$components/List';
	import { onMount } from 'svelte';
	let { data }: PageProps = $props();

	let networks: WiFiNetwork[] = [];

	onMount(async () => {
        networks = await getWiFiNetworks();
    });

	async function getWiFiNetworks() {
		const response = await fetch(config.apiURL + '/api/v1/wifi/scan');
		const networks: WiFiNetwork[] = await response.json();
		return networks.map((network) => {
			let wifiIconClass = '';

			if (network.rssi > -55) {
				wifiIconClass = 'wifi-signal-4';
			} else if (network.rssi > -65) {
				wifiIconClass = 'wifi-signal-3';
			} else if (network.rssi > -75) {
				wifiIconClass = 'wifi-signal-2';
			} else {
				wifiIconClass = 'wifi-signal-1';
			}

			return {
				ssid: network.ssid,
				bssid: network.bssid,
				signal_strength: network.rssi,
				security: network.security,
				frequency: network.frequency,
				iconProps: {
					class: wifiIconClass
				}
			};
		});
	}

	async function getNetworkInfo() {
		const response = await fetch(config.apiURL + '/api/v1/network');
		const networkInfo = await response.json();
		return networkInfo;
	}
</script>

{#await networks}
	<p>Loading...</p>
{:then wifi_networks}
	<p>Found {wifi_networks.length} WiFi Networks.</p>

	<List>
		{#each wifi_networks as network}
			<ListItem icon={WifiIcon} iconProps={network.iconProps}>
				<a href="#">{network.ssid}</a>
			</ListItem>
		{/each}
	</List>
{:catch error}
	<p>{error.message}</p>
{/await}

<div>
	{#await getNetworkInfo()}
		<p>Loading...</p>
	{:then networkInfo}
		<p>IP Address: {networkInfo.ip}</p>
		<p>Gateway: {networkInfo.gateway}</p>
		<p>DNS: {networkInfo.dns}</p>
		<p>MAC Address: {networkInfo.mac}</p>
	{:catch error}
		<p>Error fetching network info: {error.message}</p>
	{/await}
</div>

<style lang="postcss">
	@reference "tailwindcss";

	:global(.wifi-signal-4) {
	}

	:global(.wifi-signal-3 path:nth-child(2)) {
		@apply hidden;
	}

	:global(.wifi-signal-2 path:nth-child(1), .wifi-signal-2 path:nth-child(2)) {
		@apply hidden;
	}

	:global(
		.wifi-signal-1 path:nth-child(1),
		.wifi-signal-1 path:nth-child(2),
		.wifi-signal-1 path:nth-child(3)
	) {
		@apply hidden;
	}
</style>
