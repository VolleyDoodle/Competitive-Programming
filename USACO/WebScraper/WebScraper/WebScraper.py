from bs4 import BeautifulSoup
from math import radians
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import requests
import urllib
from sklearn import linear_model
bdsl = []
bathsl = []
sqftl = []
yearl = []
garagel = []
lotl = []
pricel = []
def parsepage(soup):
    for data in soup.find_all('span', {'class': 'listing-info-item font-size-sm line-height-base d-block pull-left pr-50 listing-beds'}):
        temp = data.text
        temp = temp.replace("Bd","")
        temp = temp.replace("\n", "")
        temp = int(temp)
        bdsl.append(temp)
    for data in soup.find_all('span', {'class': 'listing-info-item font-size-sm line-height-base d-block pull-left pr-50 listing-baths'}):
        temp = data.text
        temp = temp.replace("Ba", "")
        temp = temp.replace("/1", "")
        temp = temp.replace("/2", ".5")
        temp = temp.replace("\n", "")
        temp = float(temp)
        bathsl.append(temp)
    for data in soup.find_all('span', {'class': 'listing-info-item font-size-sm line-height-base d-block pull-left pr-50 listing-sqft last'}):
        temp = data.text
        #temp = temp.strip()
        temp = temp.replace("\n", "")
        temp = temp.replace("Sq Ft","")
        if "Year Built" in data.text:
            temp = temp.replace("Year Built", "")
            temp = int(temp)
            yearl.append(temp)
        else:
            temp = temp.replace(",","")
            temp = int(temp)
            sqftl.append(temp)
        
    for data in soup.find_all('span', {'class': 'listing-info-item font-size-sm line-height-base d-block pull-left pr-50 listing-garage'}):
        temp = data.text
        temp = temp.replace("\n", "")
        temp = temp.replace("Garage","")
        temp = int(temp)
        garagel.append(temp)
    for data in soup.find_all('span', {'class': 'listing-info-item font-size-sm line-height-base d-block pull-left pr-50 listing-lot-size'}):
        temp = data.text
        temp = temp.replace("\n", "")
        temp = temp.replace("Sq Ft Lot", "")
        temp = temp.replace(",","")
        if "Acres Lot" in temp:
            temp = temp.replace("Acres Lot", "")
            temp = float(temp)
            temp = temp * 43560
        temp = int(temp)
        lotl.append(temp)
    for data in soup.find_all('strong', {'class': 'listing-price d-block pull-left pr-25'}):
        temp = data.text
        temp = temp.replace("$", "")
        temp = temp.replace(",", "")
        temp = int(temp)
        pricel.append(temp)


       

for page in range(1,10):
    url = url = "https://www.mlslistings.com/Search/Result/d9acf9f6-c93f-4fa8-86b1-1a440835bd1a/" + str(page) + "?view=list"
    html = urllib.request.urlopen(url)
    soup = BeautifulSoup(html, 'html.parser')
    parsepage(soup)

 

'''print(bdsl)
print(bathsl)
print(sqftl)
print(yearl)
print(garagel)
print(lotl)
print(pricel)'''
'''for x in bdsl:
    print(x)
for x in bathsl:
    print(x)'''
'''for x in sqftl:
    print(x)'''

beds = pd.DataFrame(bdsl, columns = ["Beds"])
baths = pd.DataFrame(bathsl, columns = ["Baths"])
sqft = pd.DataFrame(sqftl, columns = ["Sqft"])
year_built = pd.DataFrame(yearl, columns = ["Year Built"])
garage = pd.DataFrame(garagel, columns = ["Garage"])
lot = pd.DataFrame(lotl, columns = ["Lot Size"])
price = pd.DataFrame(pricel, columns = ["Price"])
'''print(bds)
print(baths)
print(sqft)
print(year_built)
print(garage)
print(lot)
print(price)'''
x1 = np.array(sqft["Sqft"])
y1 = np.array(price["Price"])
plt.figure(1)
plt.scatter(sqft["Sqft"], price["Price"])
line = np.poly1d(np.polyfit(x1, y1, 1))
plt.plot (np.unique(x1), line (np.unique(x1)))
plt.xlabel("Sqft")
plt.ylabel("Price")
print(line (1574))
'''plt.figure(2)
plt.scatter(year_built["Year Built"], price["Price"])
plt.xlabel("Year Built")
plt.ylabel("Price")
plt.figure(3)
plt.scatter(sqft["Sqft"], bds["Beds"])
plt.xlabel("Sqft")
plt.ylabel("Beds")
plt.figure(4)
plt.scatter(bds["Beds"], price["Price"])
plt.xlabel("Beds")
plt.ylabel("Price")'''
plt.show()
X = pd.concat([sqft, beds], axis = 1)
X = pd.concat([X, baths ], axis = 1)
X = pd.concat([X, year_built], axis = 1)
X = pd.concat([X, garage], axis = 1)
X = pd.concat([X, lot], axis = 1)
print(X)
print(type(X))
print(X.shape)
y = pd.DataFrame(price['Price'])
print(y)
print(type(y))
print(y.shape)
regr = linear_model.LinearRegression()

regr.fit(X.values, y.values)
print("intercept: ", regr.intercept_)
print("Coefficients:")
print(regr.coef_)
ans = regr.predict([[1574, 3, 2, 1964, 2, 10018]])
print()
print(ans)