<script lang="ts">
	import type { PageProps } from './$types';
	import { page } from '$app/state';
	import {List, ListItem} from '$components/List';
	let { data }: PageProps = $props();

</script>

<div>{page.status}</div>
<h1>WiFi Settings</h1>
<List>

		<ListItem>
			hiii
		</ListItem>


</List>