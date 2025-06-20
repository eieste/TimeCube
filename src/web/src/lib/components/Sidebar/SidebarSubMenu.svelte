<script lang="ts">
	import { ChevronDownIcon, ChevronLeftIcon } from "svelte-feather-icons";
	let { children, title, icon=null } = $props();
	const Icon = icon;
	import {

	slide
} from 'svelte/transition';
	let open = $state(false);



	console.log(children);
</script>

<li class="navbar-submenu">
	<button
		type="button"
		onclick={() => {open = !open}}
	>
		{#if icon}
			<Icon size="16" class="text-gray-500" />
		{/if}
		<span class="title" data-foo="sidebar-toggle-item"
			>{title}</span>
		<ChevronDownIcon size={"16"} class={(open ? "" : "rotate-90")+" transition-transform duration-200"} />
	</button>
	{#if open}
		<ul in:slide out:slide id="dropdown-example" class={"submenu"}>
			{@render children()}
		</ul>
	{/if}

</li>

<style lang="postcss">

	@reference "tailwindcss";
	
	.navbar-submenu {
		button {
			@apply flex w-full items-center rounded-lg p-2 text-base font-normal transition duration-75 text-white hover:bg-gray-700;

			.title {
				@apply ml-3 flex-1 text-left whitespace-nowrap;
			}
		}
		.submenu {
			@apply space-y-2 py-2 overflow-hidden;
		}
	}

</style>
