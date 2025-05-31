<script lang="ts">
	import Header from './Header.svelte';
	import Navbar from '../lib/components/Navbar/Navbar.svelte';
	import NavbarItem from '../lib/components/Navbar/NavItem.svelte';
	import NavbarSubMenu from '../lib/components/Navbar/NavSubMenu.svelte';
	import NavbarSubItem from '../lib/components/Navbar/NavSubItem.svelte';
	import '../app.css';
	import type { PageProps } from './$types';
	import {BoxIcon, SettingsIcon, WifiIcon} from 'svelte-feather-icons';
	import { page } from '$app/state';
	let { children, data } = $props();

</script>

<div class="app">
	
	<Navbar>
		<NavbarItem href="/" icon={BoxIcon}>Übersicht</NavbarItem>
		<NavbarSubMenu icon={SettingsIcon} title="Einstellungen">
			<NavbarSubItem href="/settings/wifi" icon={WifiIcon}>WiFi</NavbarSubItem>
			<NavbarSubItem href="#">a</NavbarSubItem>
			<NavbarSubItem href="#">b</NavbarSubItem>
			<NavbarSubItem href="#">c</NavbarSubItem>
			<NavbarSubItem href="#">d</NavbarSubItem>
		</NavbarSubMenu>
	</Navbar>

	<main>

		<h1>{data.title}</h1>
		<div>{@html data.content}</div>


		{@render children()}
	</main>

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