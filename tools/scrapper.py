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
    if not os.path.exists('downloaded_images'):
        os.makedirs('downloaded_images')

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
url = "https://www.google.com/search?client=opera-gx&hs=zN0&sca_esv=598104924&sxsrf=ACQVn095Xhve27bpKDTTgLPvqolK5yQX8A:1705142022370&q=moba&tbm=isch&source=lnms&sa=X&ved=2ahUKEwjlr6OEldqDAxXGVKQEHfQIBlwQ0pQJegQICBAB&biw=1879&bih=977&dpr=1"  # Replace with your Google Images URL
counter = 1000 # Replace with the number of images you want to download
download_images(url, counter)
