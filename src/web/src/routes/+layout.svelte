<script lang="ts">
	  import { onMount } from 'svelte';
	import Header from './Header.svelte';
	import Sidebar from '$components/Sidebar/Sidebar.svelte';
	import SidebarItem from '$components/Sidebar/SidebarItem.svelte';
	import SidebarSubMenu from '$components/Sidebar/SidebarSubMenu.svelte';
	import SidebarSubItem from '$components/Sidebar/SidebarSubItem.svelte';
	import '../app.css';
	import type { PageProps } from './$types';
	import {BoxIcon, SettingsIcon, WifiIcon, RefreshCcwIcon} from 'svelte-feather-icons';
	import { page } from '$app/state';
	
	let { children, data } = $props();
	
	async function getSystemInfo() {
		const response = await fetch(config.apiURL+'/api/v1/system')
		const systemInfo = await response.json();
		return systemInfo;
	}

	onMount(() => {
		getSystemInfo();
		intervalId = setInterval(getSystemInfo, 5000);
		return () => {
			clearInterval(intervalId);
		};
	});

</script>

<div class="app">

	<div class="h-screen w-full overflow-hidden">

		<header class="relative top-0 left-0 right-0 bg-gray-800 text-white w-full">
			<nav class="p-2">
				<div class="flex items-center text-white my-auto">
					<a href="#" class="font-sans antialiased text-sm text-current ml-2 mr-2 block py-1 font-semibold">TimeCube</a>
					<div class="p-1 block right-0 mr-5 ml-auto ">
						<ul class="align-left list-none flex flex-row space-x-2">
							<li>
								<RefreshCcwIcon size="16" class="animate-pulse"/>
							</li>
						</ul>
					</div>
				</div>
			</nav>
		</header>

		<div class="flex h-full relative">
			<aside class="w-64 bg-gray-100 h-full overflow-y-auto">
				<Sidebar>
					<SidebarItem href="/" icon={BoxIcon}>Übersicht</SidebarItem>
					<SidebarSubMenu icon={SettingsIcon} title="Einstellungen">
						<SidebarSubItem href="/settings/wifi" icon={WifiIcon}>WiFi</SidebarSubItem>
						<SidebarSubItem href="#">a</SidebarSubItem>
						<SidebarSubItem href="#">b</SidebarSubItem>
						<SidebarSubItem href="#">c</SidebarSubItem>
						<SidebarSubItem href="#">d</SidebarSubItem>
					</SidebarSubMenu>
				</Sidebar>

			</aside>

			<main class="flex-1 bg-white bg-red-100 overflow-y-auto">
					<h1 class="text-2xl font-bold">{page.data.title}</h1>
					<hr>
					<div>
						{@render children()}
					</div>
			</main>
		</div>
	</div>

</div>


<style lang="postcss">

@reference "tailwindcss";

	.app {
		@apply flex min-h-screen;
	
		main {
			@apply flex-1 p-4;
		}
	
	}

</style>