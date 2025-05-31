<script type="ts" module>
	import { defineMeta } from '@storybook/addon-svelte-csf';
  import List from './List.svelte';
  import ListItem from './ListItem.svelte';
	import { WifiIcon } from 'svelte-feather-icons';

  
	const { Story } = defineMeta({
		title: 'Components/List',
		component: List
	});

</script>

<Story name="Basic">
	<List>
    <ListItem icon={WifiIcon}>hi</ListItem>
    <ListItem icon={WifiIcon}>hi</ListItem>
    <ListItem icon={WifiIcon}>hi</ListItem>
    <ListItem icon={WifiIcon}>hi</ListItem>
    <ListItem icon={WifiIcon}>hi</ListItem>
    <ListItem icon={WifiIcon}>hi</ListItem>
  </List>
</Story>
