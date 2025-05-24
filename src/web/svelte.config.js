import adapter from '@sveltejs/adapter-static';
import { vitePreprocess } from '@sveltejs/vite-plugin-svelte';

const config = {
	preprocess: vitePreprocess(),
	kit: {
		adapter: adapter(),
		paths: {
			base: ''
		},
		alias: {
			components: 'src/lib/components'
		},
		outDir: '../mainesp/data/web'
	}
};

export default config;