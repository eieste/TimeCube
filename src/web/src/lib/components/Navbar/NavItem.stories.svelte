<script module lang="ts">

	import { defineMeta } from '@storybook/addon-svelte-csf';
	import Navbar from './Navbar.svelte';
	import NavItem from './NavItem.svelte';

	export interface NavItemProps {
		title?: string;
		pillContent?: string;
		pillType?: ('note' | 'primary')[];
		href?: string;
	}

	const render = (args: NavItemProps) => ({
		Component: Navbar,
		props: {
			default: {
				Component: NavItem,
				props: args,
				children: args.title
			}
		}
	});

	const {Story}  = defineMeta({
		title: 'Components/NavItem',
		component: NavItem,
		args: {
			title: "Foo",
			pillContent: "",
			pillType: ["note", "primary"],
			href: ""
		},
		render
	});
</script>

<Story name="foo" />