<script lang="ts">
	let { href = null, children, icon = null, active = false } = $props();
	const Icon = icon;
</script>

<li class={active ? 'navitem active' : 'navitem'}>
	<a {href} class={'navlink'}>
		{#if icon}
			<Icon size="16" class="text-gray-500" />
		{/if}
		<span class="navtext">
			{#if typeof children === 'string'}
				{children}
			{:else}
				{@render children()}
			{/if}
		</span>
	</a>
</li>

<style lang="postcss">
	@reference "tailwindcss";

	li.navitem {
			.navtext {
				@apply ml-3 flex-1 whitespace-nowrap;
			}

			.navlink {
				@apply flex w-full items-center rounded-lg p-2 pl-11 text-base font-normal text-white transition duration-75 hover:bg-gray-700;
			}
		}
	

	li.active.navitem {
			.navtext {
				@apply font-semibold;
			}
			.navlink {
				@apply bg-blue-900 text-white;
			}
		}
	
</style>
