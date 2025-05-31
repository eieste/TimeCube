import hug


@hug.get('/api/v1/wifi/scan')
def wifi_scan():
    return [
         {
            "rssi": -70,
            "ssid": "MockedSSID",
            "bssid": "00:11:22:33:44:55",
            "channel": 6,
            "secure": True
            }, 
            {
            "rssi": -65,
            "ssid": "AnotherMockedSSID",
            "bssid": "66:77:88:99:AA:BB",
            "channel": 11,
            "secure": False
            },
            {
            "rssi": -80,
            "ssid": "YetAnotherMockedSSID",
            "bssid": "CC:DD:EE:FF:00:11",
            "channel": 1,
            "secure": True
            }
    ]
