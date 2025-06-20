import adapter from '@sveltejs/adapter-static';
import { vitePreprocess } from '@sveltejs/vite-plugin-svelte';

const config = {
	preprocess: vitePreprocess(),
		path: {
			base: '',
			relative: false
		},
	kit: {
		adapter: adapter({
			// Hier den Zielpfad angeben:
			pages: '../mainesp/data/web',
			assets: '../mainesp/data/web',
			fallback: null,
			precompress:false,
			strict: false,
		}),
		alias: {
			"$components": 'src/lib/components',
			"$config": 'src/config.ts',
		}
	}
};

export default config;