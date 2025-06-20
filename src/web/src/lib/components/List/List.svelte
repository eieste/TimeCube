<script lang="ts">
    const { children=null } = $props();
</script>

<ul class="list">
    {#if typeof children === 'function'}
        {@render children()}
    {/if}
</ul>

  
<style lang="postcss">
	@reference "tailwindcss";
    ul {
        &.list {
            @apply flex flex-col gap-0.5 min-w-60;
        }
    }
</style>