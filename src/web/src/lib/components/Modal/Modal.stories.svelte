<script lang="ts" >
    import { defineMeta } from '@storybook/addon-svelte-csf';
    import Modal from './Modal.svelte';


    const { Story } = defineMeta({
		title: 'Components/Modal',
		component: Modal,
        argTypes: {
            title: {
                control: 'text',
                description: 'The title of the modal',
                defaultValue: null,
            },
            closeable: {
                control: 'boolean',
                description: 'Whether the modal can be closed',
                defaultValue: true,
            }
        },
	});
</script>

<Story name="Basic">
    <Modal>
        {#snippet content()}
            <p>This is the content of the modal.</p>
        {/snippet}

        {#snippet actions()}
            <button type="button" class="btn btn-primary">Action</button>
            <button type="button" class="btn btn-secondary">Cancel</button>
        {/snippet}
    </Modal>
</Story>

