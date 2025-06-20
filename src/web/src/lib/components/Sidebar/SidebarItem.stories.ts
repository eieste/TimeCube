
import type { Meta, StoryObj } from '@storybook/svelte';
  import SidebarItem from './SidebarItem.svelte';
  import Sidebar from './Sidebar.svelte';
  import * as allIcons from 'svelte-feather-icons'

const meta: Meta = {
  title: 'Components/Sidebar/SidebarItem',
  component: SidebarItem,
  args:{
    icon: allIcons.ActivityIcon, // Standard-Icon
    children: "Start"
  },
  argTypes: {
    href: { control: 'text' },
    pillContent: { control: 'text' },
    pillType: { control: 'select', options: ["note", "primary"] },
    icon: {
      control: 'select',
      options: Object.keys(allIcons), // Alle Icon-Namen als Optionen
      mapping: allIcons
    },
    children: { control: 'text' },
    active: { control: 'boolean' },

  },
  decorators: [
    // Dekorator-Wrapper, um NavItem korrekt im Kontext zu rendern
    (Story) => ({
      Component: Sidebar,
      props: {
        $$slots: {
          default: [Story],
        },
        $$scope: {},
      },
    }),
  ],
};

export default meta;

type Story = StoryObj<typeof SidebarItem>;

export const Default: Story = {
  args: {
    children: 'Start',
    href: '/',
    icon: allIcons.ActivityIcon,
    active: false,
  },
};