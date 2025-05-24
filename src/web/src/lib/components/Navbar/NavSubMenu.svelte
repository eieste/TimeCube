<script lang="ts">
	let { children, title } = $props();
	let open = $state(false);
</script>

<li class="navbar-submenu">
	<button
		type="button"
		onclick={() => {open = !open}}
	>
		<svg
			class="h-6 w-6 flex-shrink-0 text-gray-500 transition duration-75 group-hover:text-gray-900 dark:text-gray-400 dark:group-hover:text-white"
			fill="currentColor"
			viewBox="0 0 20 20"
			xmlns="http://www.w3.org/2000/svg"
			><path
				fill-rule="evenodd"
				d="M10 2a4 4 0 00-4 4v1H5a1 1 0 00-.994.89l-1 9A1 1 0 004 18h12a1 1 0 00.994-1.11l-1-9A1 1 0 0015 7h-1V6a4 4 0 00-4-4zm2 5V6a2 2 0 10-4 0v1h4zm-6 3a1 1 0 112 0 1 1 0 01-2 0zm7-1a1 1 0 100 2 1 1 0 000-2z"
				clip-rule="evenodd"
			></path></svg
		>
		<span class="title" data-foo="sidebar-toggle-item"
			>{title}</span
		>
		<svg
			class="h-6 w-6"
			fill="currentColor"
			viewBox="0 0 20 20"
			xmlns="http://www.w3.org/2000/svg"
			><path
				fill-rule="evenodd"
				d="M5.293 7.293a1 1 0 011.414 0L10 10.586l3.293-3.293a1 1 0 111.414 1.414l-4 4a1 1 0 01-1.414 0l-4-4a1 1 0 010-1.414z"
				clip-rule="evenodd"
			></path></svg
		>
	</button>
	{#if open }
		<ul id="dropdown-example" class="submenu">
			{@render children()}
		</ul>
	{/if}

</li>

<style lang="postcss">

	@reference "tailwindcss";
	
	.navbar-submenu {
		button {
			@apply flex w-full items-center rounded-lg p-2 text-base font-normal text-gray-900 transition duration-75 hover:bg-gray-100 dark:text-white dark:hover:bg-gray-700;

			.title {
				@apply ml-3 flex-1 text-left whitespace-nowrap;
			}
		}
		.submenu {
			@apply space-y-2 py-2;
		}
	}

</style>
