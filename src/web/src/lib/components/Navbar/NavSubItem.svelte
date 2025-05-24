<script lang="ts">
	let { href=null, children } = $props();

</script>

<li>
	<a href={href} class="navlink">{@render children()}</a>
</li>

<style lang="postcss">
	@reference "tailwindcss";


	.navlink {
		@apply flex w-full items-center rounded-lg p-2 pl-11 text-base font-normal text-gray-900 transition duration-75 hover:bg-gray-100 dark:text-white dark:hover:bg-gray-700;
	}
</style>
