import cv2
import numpy as np

# Örnek görüntüyü ve ROI (Region of Interest) belirleme
image = cv2.imread("C:\SS\indir.jpg")  # Aranacak görüntü
roi = cv2.imread("C:\SS\indir2.png")      # Aranacak nesnenin olduğu küçük bölge

# ROI'nin HSV renk uzayına dönüştürülmesi
hsv_roi = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)
hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# ROI'nin histogramını oluşturma
roi_hist = cv2.calcHist([hsv_roi], [0], None, [180], [0, 180])
cv2.normalize(roi_hist, roi_hist, 0, 255, cv2.NORM_MINMAX)

# Back Projection hesaplama
back_proj = cv2.calcBackProject([hsv_image], [0], roi_hist, [0, 180], 1)

# Sonucu göstermek için bir maskeleme işlemi uygula
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5, 5))
back_proj = cv2.filter2D(back_proj, -1, kernel)

# Eşikleme ve birleştirme
_, thresh = cv2.threshold(back_proj, 50, 255, cv2.THRESH_BINARY)
result = cv2.bitwise_and(image, image, mask=thresh)

# Sonuçları göster
cv2.imshow("Back Projection", back_proj)
cv2.imshow("Thresholded Result", result)
cv2.waitKey(0)
cv2.destroyAllWindows()

