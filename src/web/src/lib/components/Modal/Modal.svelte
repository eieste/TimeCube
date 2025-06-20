<script lang="ts">
  import { XIcon } from "svelte-feather-icons";
  
  export const {children, title=null, closeable=true, actions=null, content=null} = $props();

  /*
    {#snippert content()}
        <p>This is the content of the modal.</p>
    {/snippet}

    {#snippet actions()}
        <button type="button" class="btn btn-primary">Action</button>
        <button type="button" class="btn btn-secondary">Cancel</button>
    {/snippet}
  */

</script>


<div class="flex justify-center">
  <div class="fixed inset-0 bg-slate-950/50 flex justify-center items-center pointer-events-none transition-opacity duration-300 ease-out z-[9999]" id="exampleModal" aria-hidden="true">
    <div class="bg-white rounded-xl shadow-2xl shadow-slate-950/5 border border-slate-200 w-1/3 scale-95">
      <div class="p-4 pb-2 flex justify-between items-center">
        
        {#if title}
          <h1 class="text-lg text-slate-800 font-semibold">{title}</h1>
        {/if}

        {#if closeable}
          <button type="button" data-dismiss="modal" aria-label="Close" class="inline-grid place-items-center border align-middle select-none font-sans font-medium text-center transition-all duration-300 ease-in disabled:opacity-50 disabled:shadow-none disabled:pointer-events-none data-[shape=circular]:rounded-full text-sm min-w-[34px] min-h-[34px] rounded-md bg-transparent border-transparent text-slate-200-foreground hover:bg-slate-200/10 hover:border-slate-200/10 shadow-none hover:shadow-none outline-none absolute right-2 top-2">
            <XIcon size="1.5x" class="text-bold" />
          </button>
        {/if}

      </div>

      <div class="p-4 pt-2 text-slate-600">

        {@render content()}

      </div>

      <div class="p-4 flex justify-end gap-2">
        {@render actions()}

        <button type="button" data-dismiss="modal" class="inline-flex items-center justify-center border align-middle select-none font-sans font-medium text-center transition-all duration-300 ease-in disabled:opacity-50 disabled:shadow-none disabled:cursor-not-allowed data-[shape=pill]:rounded-full data-[width=full]:w-full focus:shadow-none text-sm rounded-md py-2 px-4 bg-transparent border-transparent text-red-500 hover:bg-red-500/10 hover:border-red-500/10 shadow-none hover:shadow-none outline-none">Close</button>
        <button type="button" class="inline-flex items-center justify-center border align-middle select-none font-sans font-medium text-center transition-all duration-300 ease-in disabled:opacity-50 disabled:shadow-none disabled:cursor-not-allowed data-[shape=pill]:rounded-full data-[width=full]:w-full focus:shadow-none text-sm rounded-md py-2 px-4 shadow-sm hover:shadow-md bg-slate-800 border-slate-800 text-slate-50 hover:bg-slate-700 hover:border-slate-700">Get Started</button>
      </div>

    </div>
  </div>
</div>
