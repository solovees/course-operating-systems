
# coding: utf-8

# In[9]:

from ctypes import windll, byref, Structure, Array, wintypes
class ULONGLONG(Structure):
    _fields_ = [("RAM", wintypes.ULONG),]
unlonglong = ULONGLONG();
kernel32 = windll.kernel32
kernel32.GetPhysicallyInstalledSystemMemory(byref(unlonglong))
ram = unlonglong.RAM/1024/1024
print("RAM: ", ram)


# In[ ]:



