<script lang="ts">
	import { page } from '$app/state';
	let {pillContent=null, pillType=null, href=null, children=null, icon=null, active=null} = $props();
	const Icon = icon;


	if(active === undefined || active === null) {
		active = href === page.route.id;
	}


	console.log(href, page.route.id);

	console.log(active);
</script>


<li class={active ? "navbaritem active" : "navbaritem"}>
	<a href={href} class={"navlink"}>
		{#if icon}
			<Icon size="16" class={"navicon"} />
		{/if}
		<span class="navtext">
			{#if typeof children === "string"}
				{children}
			{:else}
				{@render children()}
			{/if}
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
			@apply flex items-center rounded-lg p-2 font-normal text-gray-300 hover:bg-gray-700;
		}

		.navtext {
			@apply ml-3 flex-1 whitespace-nowrap;
		}

		.navicon {
			@apply h-6 w-6 text-gray-400;
		}

		.navpill {
			@apply ml-3 inline-flex items-center justify-center rounded-full text-sm font-medium;
			&.note {
				@apply px-2 bg-gray-700 text-gray-300;
			}

			&.primary {
				@apply h-3 w-3 p-3 bg-blue-900 text-blue-200;
			}
		}
	}

	li.navbaritem.active {
		a.navlink {
			@apply bg-gray-900 text-white;
			.navicon {
				@apply text-white;
			}
			.navtext {
				@apply text-white font-semibold;
			}
			.navpill {
				@apply bg-blue-900 text-blue-200;
			}
		}
	}
</style>
