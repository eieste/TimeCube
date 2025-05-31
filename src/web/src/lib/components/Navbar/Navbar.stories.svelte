<script module>
	import { defineMeta } from '@storybook/addon-svelte-csf';

	import Navbar from './Navbar.svelte';

	import NavItem from './NavItem.svelte';
	
	import NavSubMenu from './NavSubMenu.svelte';
	import NavSubItem from './NavSubItem.svelte';
	import { ArrowRightIcon } from 'svelte-feather-icons';

	const { Story } = defineMeta({
		title: 'Components/Navbar',
		component: Navbar
	});
</script>

<Story name="Basic">
	<Navbar>
		<NavItem href="#" icon={ArrowRightIcon}>foo</NavItem>
	</Navbar>
</Story>

<Story name="WithProp">
	<Navbar>
		<NavItem href="#" icon={ArrowRightIcon}>foo</NavItem>
		<NavSubMenu title="FooBar"  icon={ArrowRightIcon}>
            <NavSubItem href="" icon={ArrowRightIcon}>foo</NavSubItem>
            <NavSubItem href="" icon={ArrowRightIcon}>foo</NavSubItem>
            <NavSubItem href="" icon={ArrowRightIcon}>foo</NavSubItem>
        </NavSubMenu>
	</Navbar>
</Story>
