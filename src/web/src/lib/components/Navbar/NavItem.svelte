<script lang="ts">
	let {pillContent=null, pillType=null, title=null, href, children=null} = $props();
</script>

<li class="navbaritem">
	<a href={href} class="navlink">
		<svg
			class="h-6 w-6 flex-shrink-0 text-gray-500 transition duration-75 group-hover:text-gray-900 dark:text-gray-400 dark:group-hover:text-white"
			fill="currentColor"
			viewBox="0 0 20 20"
			xmlns="http://www.w3.org/2000/svg">
			<path
				d="M5 3a2 2 0 00-2 2v2a2 2 0 002 2h2a2 2 0 002-2V5a2 2 0 00-2-2H5zM5 11a2 2 0 00-2 2v2a2 2 0 002 2h2a2 2 0 002-2v-2a2 2 0 00-2-2H5zM11 5a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2h-2a2 2 0 01-2-2V5zM11 13a2 2 0 012-2h2a2 2 0 012 2v2a2 2 0 01-2 2h-2a2 2 0 01-2-2v-2z"
			>
			</path>
		</svg>
		{@render children?.()}
		<span class="navtext">
			{title}
		</span>

		{#if pillContent && pillType}
			<span class={pillType == "note" ? "navpill note" : "primary navpill"}>{pillContent}</span>
		{/if}
	</a>
</li>

<style lang="postcss">
	@reference "tailwindcss";

	li.navbaritem {

		a.navlink {
			@apply flex items-center rounded-lg p-2 text-base font-normal text-gray-900 hover:bg-gray-100 dark:text-white dark:hover:bg-gray-700;
		}

		.navtext {
			@apply ml-3 flex-1 whitespace-nowrap;
		}

		.navpill {
			@apply ml-3 inline-flex items-center justify-center rounded-full text-sm font-medium;
			&.note {
				@apply bg-gray-200 px-2 text-gray-800 dark:bg-gray-700 dark:text-gray-300;
			}

			&.primary {
				@apply h-3 w-3 bg-blue-200 p-3 text-blue-600 dark:bg-blue-900 dark:text-blue-200;
			}
		}
	}
</style>
