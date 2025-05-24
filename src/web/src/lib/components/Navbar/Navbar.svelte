<script lang="ts">
	let {children} = $props();
</script>

<aside class="navbar-sidebar">
	<div class="sidebar">
		<ul class="navbar-list blubl">
			{@render children()}
		</ul>
	</div>
</aside>

<style lang="postcss">
	@reference "tailwindcss";

	.navbar-sidebar {
		@apply h-screen w-64;

		.sidebar {
			@apply overflow-y-auto bg-gray-50 px-3 py-4 dark:bg-gray-800 h-full;

			
			.navbar-list {
				@apply space-y-2;
			}
		}
		
	}
</style>
