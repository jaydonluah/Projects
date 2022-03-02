from selenium.webdriver.support import expected_conditions as EC
import datetime as dt
from dateutil import relativedelta as rd
import time

# User inputs
global PATH
PATH = input("Path of chromedriver (eg C:\Program Files (x86)\chromedriver.exe): ")
global username
username = input("Username: ")
global password
password = input("Password: ")
global targetdate
targetdate = dt.datetime(2022, 2, 1)


def bbdc_bot():
    # chrome running headless (ie google chrome will not pop up)
    chrome_options = Options()
    chrome_options.add_argument("--headless")
    chrome_options.add_argument("--disable-gpu")
    driver = webdriver.Chrome(PATH, options=chrome_options)
    driver.get("https://info.bbdc.sg/members-login/")
    # login page
    try:
        username = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "txtNRIC")))
        username.send_keys(username)
        password = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "txtPassword")))
        password.send_keys(password)
        login = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "loginbtn")))
        login.click()
        print("Login successful")
    except Exception as e:
        print(e)
        print("Error at login")
        driver.quit()
    # not secure page
    #try:
    #    proceed = WebDriverWait(driver, 10).until(
    #        EC.presence_of_element_located((By.ID, "proceed-button")))
    #    proceed.click()
    #    print("Login successful")
    #except Exception as e:
    #    print(e)
    #    print("Error at secure page")
    #    driver.quit()
    # home page
    try:
        # click TP simulator booking
        WebDriverWait(driver, 10).until(
            EC.frame_to_be_available_and_switch_to_it(driver.find_element_by_xpath("/html/frameset/frameset/frameset/frame[1]")))
        booking = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.LINK_TEXT, "Booking")))
        booking.click()
        # click module 1 and submit
        driver.switch_to.default_content()
        WebDriverWait(driver, 10).until(
            EC.frame_to_be_available_and_switch_to_it(driver.find_element_by_name('mainFrame')))
        optin = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.NAME, "optTest")))
        optin.click()
        submit = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.NAME, "btnSubmit")))
        submit.click()
        print("Simulator Module 1")
        time.sleep(5)
    except Exception as e:
        print(e)
        print("Error at home page")
        driver.quit()
    # month session and day selector
    try:
        dec = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.XPATH, "/html/body/table/tbody/tr/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[1]/td[2]/table/tbody/tr[1]/td[2]/input")))
        dec.click()
        jan = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.XPATH, "/html/body/table/tbody/tr/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[1]/td[2]/table/tbody/tr[1]/td[3]/input")))
        jan.click()
        feb = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.XPATH, "/html/body/table/tbody/tr/td[2]/form/table/tbody/tr[2]/td/table/tbody/tr[1]/td[2]/table/tbody/tr[1]/td[4]/input")))
        feb.click()
        sessions = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.NAME, "allSes")))
        sessions.click()
        days = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.NAME, "allDay")))
        days.click()
        search = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.NAME, "btnSearch")))
        search.click()
        print("Looking for slots")
    except Exception as e:
        print(e)
        print("Error when selecting month, session and day")
        driver.quit()
    # available slots
    try:
        # finding first available slot and checking if it is within one month
        firstslot = WebDriverWait(driver, 180).until(
            EC.presence_of_element_located(
                (By.XPATH, "/html/body/table/tbody/tr/td[2]/form/table[1]/tbody/tr[9]/td/table/tbody/tr[3]/td[1]")))
        firstslot = firstslot.text[:6] + firstslot.text[8:10]
        firstslot = dt.datetime.strptime(firstslot, "%d/%m/%y")
        if firstslot < targetdate:
            # book earliest available slot if it is before target date
            sessionbutton = WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.NAME, "slot")))
            sessionbutton.click()
            submitbutton = WebDriverWait(driver, 10).until(
                EC.presence_of_element_located(
                    (By.XPATH, "/html/body/table/tbody/tr/td[2]/form/table[2]/tbody/tr[1]/td[1]/input[2]")))
            submitbutton.click()
            confirmbutton = WebDriverWait(driver, 10).until(
                EC.presence_of_element_located(
                    (By.XPATH, "/html/body/table/tbody/tr/td[2]/form/table/tbody/tr[14]/td[2]/input[2]")))
            confirmbutton.click()
            date = firstslot.strftime(("%d/%m/%y"))
            print("Available slot before target date. Slot booked. Slot date:", date)
            global booked
            booked = 1
            time.sleep(5)
            driver.quit()
        else:
            date = firstslot.strftime(("%d/%m/%y"))
            print("Earliest slot is after target date. Earliest date:", date)
            now = dt.datetime.now()
            currenttime = now.strftime("%d/%m/%y %H:%M")
            print("Last check:", currenttime)
            driver.quit()
            time.sleep(60)
    except Exception as e:
        print(e)
        print("Error when finding available slot")
        driver.quit()

while True:
    bbdc_bot()
