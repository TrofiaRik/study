import urllib.request
import urllib.parse
import urllib.error
import json

# address=1600+Amphitheatre+Parkway,+Mountain+View,+CA&key=YOUR_API_KEY
service_url = 'https://maps.googleapis.com/maps/api/geocode/json?'
api_key = 'xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx'

while True:
    address = input('Enter location: ')
    if len(address) < 1:
        break

    # Add also the API key
    url = service_url + urllib.parse.urlencode({
        'address': address,
        'key': api_key
    })

    print('Retrieving', url)
    url_handle = urllib.request.urlopen(url)
    # print('url_handle (containing request) var: ', url_handle)
    data = url_handle.read().decode()
    print('Retrieved', len(data), 'characters')
    # print('My data blob: ', data)

    try:
        js = json.loads(data)
    except:
        js = None
    if not js or 'status' not in js or js['status'] != 'OK':
        print('!!====!! Failure To Retrieve !!====!!')
        print(data)
        continue

    print(json.dumps(js, indent=4))

    lat = js["results"][0]["geometry"]["location"]["lat"]
    lng = js["results"][0]["geometry"]["location"]["lng"]
    short = js["results"][0]["address_components"][0]["short_name"]
    location = js["results"][0]["formatted_address"]
    print('lat', lat, 'lng', lng)
    print(location, f'and the short name is {short}')
