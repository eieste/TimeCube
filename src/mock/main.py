import hug

def cors_support(response, *args, **kwargs):
    response.set_header('Access-Control-Allow-Origin', '*')


@hug.get('/api/v1/wifi/scan', requires=cors_support)
def wifi_scan():
    return [
         {
            "rssi": -80,
            "ssid": "MockedSSID",
            "bssid": "00:11:22:33:44:55",
            "channel": 6,
            "secure": True
            }, 
            {
            "rssi": -70,
            "ssid": "AnotherMockedSSID",
            "bssid": "66:77:88:99:AA:BB",
            "channel": 11,
            "secure": False
            },
            {
            "rssi": -60,
            "ssid": "YetAnotherMockedSSID",
            "bssid": "CC:DD:EE:FF:00:11",
            "channel": 1,
            "secure": True
            },
            {
            "rssi": -50,
            "ssid": "YetAnotherMockedSSID",
            "bssid": "CC:DD:EE:FF:00:11",
            "channel": 1,
            "secure": True
            }
    ]



@hug.get('/api/v1/network', requires=cors_support)
def network_info():
    return {
        "ip": "192.168.1.100",
        "netmask": "255.255.255.0",
        "gateway": "192.168.1.1",
        "mac": "33:44:55:66:77:88",
        "dns": "8.8.8.8",
        "ssid": "MockedSSID",
        "rssi": -70,
    }

@hug.get('/api/v1/system', requires=cors_support)
def system_info():
    return {
        "initialized": True,
        "version": "1.0.0",
        "restart_required": False,
    }