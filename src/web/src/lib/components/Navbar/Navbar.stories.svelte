<script module>
	import { defineMeta } from '@storybook/addon-svelte-csf';

	import Navbar from './Navbar.svelte';

	import NavItem from './NavItem.svelte';
	
	import NavSubMenu from './NavSubMenu.svelte';
	import NavSubItem from './NavSubItem.svelte';

	const { Story } = defineMeta({
		title: 'Components/Navbar',
		component: Navbar
	});
</script>

<Story name="Basic">
	<Navbar>
		<NavItem href="#">foo</NavItem>
	</Navbar>
</Story>

<Story name="WithProp">
	<Navbar>
		<NavItem href="#">foo</NavItem>
		<NavSubMenu title="FooBar">
            <NavSubItem href="">foo</NavSubItem>
            <NavSubItem href="">foo</NavSubItem>
            <NavSubItem href="">foo</NavSubItem>
        </NavSubMenu>
	</Navbar>
</Story>
