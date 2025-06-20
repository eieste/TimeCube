<script lang="ts">

    interface iconProps {
        size?: string;
        class?: string;
    }

    interface ListItemProps {
        children?: any;
        icon?: any;
        iconProps?: Record<string, string>;
    }

    const iconDefaultProps = {
        "size": `16`,
        "class": `text-slate-600`
    };  

    const { children=null, icon=null, iconProps={} }: ListItemProps = $props();

    const iconMgedProps = {
        ...iconDefaultProps,
        ...iconProps
    };
    console.log(iconMgedProps)

    const Icon = icon;
</script>

<li class="list-item">
    <span class="list-label">
        {#if Icon}
            <div class={`icon ${iconMgedProps.class}`}>
                <Icon {...{iconMgedProps}} />
            </div>
        {/if}
    </span>
    {#if typeof children === 'function'}
        {@render children()}
    {:else}
        {children}
    {/if}
</li>

<style lang="postcss">
	@reference "tailwindcss";
    
    li.list-item {
        @apply flex items-center cursor-pointer py-1.5 px-2.5 rounded-md align-middle select-none font-sans transition-all duration-300 ease-in aria-disabled:opacity-50 aria-disabled:pointer-events-none bg-transparent text-slate-600 hover:text-slate-800 hover:bg-slate-200 focus:bg-slate-200 focus:text-slate-800 data-[selected=true]:bg-slate-200 data-[selected=true]:text-black;

        .icon {
            .wifi-signal-1{
                @apply text-red-500;
            }
        }

        .list-label {
            @apply grid place-items-center shrink-0 me-2.5;
        }
    }


</style>