export type WiFiNetwork = {
    ssid: string;
    bssid: string;
    rssi: number; // Signal strength in dBm
    security: boolean;
    channel: number; // Channel number
 };