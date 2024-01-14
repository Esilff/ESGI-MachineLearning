import requests
from bs4 import BeautifulSoup
import os
import re
import urllib

def download_images(url, count):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    images = soup.find_all('img', {'src': re.compile('gstatic.com')})

    # Create directory for saving images if it does not exist
    if not os.path.exists('moba'):
        os.makedirs('moba')

    for i, img in enumerate(images[:count]):
        try:
            img_url = img['src']
            img_data = requests.get(img_url).content
            with open(f'downloaded_images/img_{i+1}.jpg', 'wb') as handler:
                handler.write(img_data)
            print(f'Image {i+1} downloaded')
        except Exception as e:
            print(f'Error downloading image {i+1}: {e}')

# Example usage
url = "https://www.google.com/search?client=opera-gx&hs=pqn&sca_esv=598412653&sxsrf=ACQVn0-w1rAuy7rALdq83r787VRmgbUG6g:1705252719130&q=rts+game&tbm=isch&source=lnms&sa=X&ved=2ahUKEwiCuc20sd2DAxVPcKQEHeddCRkQ0pQJegQIDhAB&biw=1879&bih=977&dpr=1"
counter = 1000 # Replace with the number of images you want to download
download_images(url, counter)
