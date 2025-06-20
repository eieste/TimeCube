<script module>
	import { defineMeta } from '@storybook/addon-svelte-csf';

	import Sidebar from './Sidebar.svelte';

	import SidebarItem from './SidebarItem.svelte';
	
	import SidebarSubMenu from './SidebarSubMenu.svelte';
	import SidebarSubItem from './SidebarSubItem.svelte';
	import { ArrowRightIcon } from 'svelte-feather-icons';

	const { Story } = defineMeta({
		title: 'Components/Sidebar',
		component: Sidebar
	});
</script>

<Story name="Basic">
	<Sidebar>
		<SidebarItem href="#" icon={ArrowRightIcon}>foo</SidebarItem>
	</Sidebar>
</Story>

<Story name="WithProp">
	<Sidebar>
		<SidebarItem href="#" icon={ArrowRightIcon}>foo</SidebarItem>
		<SidebarSubMenu title="FooBar"  icon={ArrowRightIcon}>
            <SidebarSubItem href="" icon={ArrowRightIcon}>foo</SidebarSubItem>
            <SidebarSubItem href="" icon={ArrowRightIcon}>foo</SidebarSubItem>
            <SidebarSubItem href="" icon={ArrowRightIcon}>foo</SidebarSubItem>
        </SidebarSubMenu>
	</Sidebar>
</Story>
