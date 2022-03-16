
import pip

import os
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys
import time
import urllib3
from bs4 import BeautifulSoup
import csv
import pandas as pd
from pandas import DataFrame
import xlsxwriter


    
column=['Title','Body']
dfBA=DataFrame(columns=column)
dfT=DataFrame(columns=[0,1,2,3,4])
content=[]    




chromedriver = "c:/Chromedriver/chromedriver"
os.environ["webdriver.chrome.driver"] = chromedriver

options = webdriver.ChromeOptions()
options.add_experimental_option('excludeSwitches', ['enable-logging'])

driver = webdriver.Chrome(chromedriver,chrome_options=options)
driver.get("https://medium.com/search?q=data%20science")


scrape()

ScrollNumber = 50
for i in range(1,ScrollNumber):
    driver.execute_script("window.scrollTo(1,50000)")
    time.sleep(5)

file = open('DS.html', 'w')
file.write(driver.page_source)

file.close()

driver.close()


http=urllib3.PoolManager()


def scrape():
    data = open('/home/DS.html','r')
    soup = BeautifulSoup(data, 'html.parser')
    print("stupid")
    #workbook = xlsxwriter.Workbook('c:/Chromedriver/hello.xlsx')
    #worksheet = workbook.add_worksheet()

    #worksheet.write('A1', 'Hello..')

    #workbook.close()
    for links in soup.find_all('div', {'class': 'postArticle-readMore'}):
        link = links.find('a').get('href')
        
        Blog_post(link)

def Blog_post(link):
    try:
        print(link)
        blogData = http.request('GET', link)
        soup = BeautifulSoup(blogData.data, 'html.parser')
        article = ''
        tags = []
        heading = soup.find('h1').text
        for para in soup.find_all('p'):
            p = para.text
        p = p.strip('/u')
        article = article + ' ' + p


        for mtags in soup.find_all('a', {'class ': 'link u - baseColor — link'}):
            tags.append(mtags.text)
            # CreateDataFrame(list())
            someList = [heading, article, tuple(tags)]
            # print(someList[0])
            
            
            CreateDataFrame(someList)
    except:
        pass 
    



def CreateDataFrame(somelist):
        t={}
        d={'title':[somelist[0]],'body':[somelist[1]]}
        for n in range(5):
            if len(somelist[2])>n:
                t[n]=[somelist[2][n]]
            else:
                t[n]=['0']
        todf=dataframe(data=d)
        global dfba,dft
        
        
        dfBA=dfBA.append(toDf)
        print(dfBA)
        dfT=dfT.append(DataFrame(data=t))

        
        

        okList = []
        for cl in dfT.columns:
            for n in dfT[cl]:
                okList.append(n)
        okList = list(set(okList))
        newDFT = DataFrame(columns=okList)
        for x in range(dfT.count()[0]):
            someDict = {}
            for d in okList:
                rowdata = list(dfT.iloc[x])
                if d in rowdata:
                    someDict[d] = 1
                else:
                    someDict[d] = 0
            newDFT = newDFT.append(someDict, ignore_index=True)
        newDFT.to_csv('c:/Chromedriver/DSTags.csv')
        worksheet.write('A1', newDFT)

        for column in dfBA.columns:
            for idx in dfBA[column].index:
                dfBA.get_value(idx, column)

        dfBA.to_csv('c:/Chromedriver/RData.csv')
        worksheet.write('B1', newDFT)
