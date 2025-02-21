import cv2
import numpy as np

# Görüntüyü ve şablonu yükleme
image = cv2.imread("C:\SS\image2.jpg")
template = cv2.imread("C:\SS\Image.jpg")  # Şablonu gri tonlamalı oku
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)  # Ana görüntüyü gri tonlamaya çevir

# Şablon eşleme yöntemini seç (TM_CCOEFF_NORMED kullanıyoruz)
result = cv2.matchTemplate(gray, template, cv2.TM_CCOEFF_NORMED)

# En iyi eşleşme noktalarını bul
min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)

# Şablonun genişliği ve yüksekliği
w, h = template.shape[::-1]

# Eşleşen bölgeye dikdörtgen çiz
cv2.rectangle(image, max_loc, (max_loc[0] + w, max_loc[1] + h), (0, 255, 0), 2)

# Sonucu göster
cv2.imshow("Template Matching Result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
