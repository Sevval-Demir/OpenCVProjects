#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <cassert>
#include <opencv2/imgproc/imgproc_c.h>  i
#include <opencv2/highgui/highgui_c.h>

//int g_slider_position = 0;  // Trackbar'ýn pozisyonu
//CvCapture* g_capture = NULL;  // Video kaynaðýný tutacak
//
//// Trackbar kaydýrýldýðýnda bu fonksiyon çalýþacak
//void onTrackbarSlide(int pos)
//{
//   // Trackbar pozisyonuna göre video karesine git
//    cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
//}

IplImage* doPyrDown(IplImage* in, int filter = IPL_GAUSSIAN_5x5) {
	assert(in->width % 2 == 0 && in->height % 2 == 0); // Giriþ görüntüsünün çift boyutlarda olduðundan emin ol

	IplImage* out = cvCreateImage(cvSize(in->width / 2, in->height / 2), in->depth, in->nChannels);
	cvPyrDown(in, out, filter);
	return out;
}

	IplImage* doCanny(IplImage * in, double lowThresh, double highThresh, double aperture) {
		if (in->nChannels != 1) {
			std::cerr << "Hata: Canny yalnýzca gri tonlama (tek kanal) görüntülerini iþler!" << std::endl;
			return nullptr;
		}

		CvSize size = cvGetSize(in); // Boyutlarý al
		IplImage* out = cvCreateImage(size, IPL_DEPTH_8U, 1); // Çýktý görüntüsünü oluþtur

		cvCanny(in, out, lowThresh, highThresh, aperture); // Canny kenar algýlama

		return out; // Çýkýþ görüntüsünü döndür
	}


int main(int argc, char** argv) {

#pragma region Display a Picture
    // Resmi renkli olarak yükle
   //IplImage* img = cvLoadImage("C:\\SS\\Image.jpg");

   //// Pencereyi oluþtur
   //cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);

   //// Resmi pencereye göster
   //cvShowImage("Example1", img);

   //// Bir tuþa basýlana kadar bekle
   //cvWaitKey(0);

   //// Kaynaklarý serbest býrak ve pencereyi kapat
   //cvReleaseImage(&img);
   //cvDestroyWindow("Example1");


   //cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
   //CvCapture* capture = cvCreateFileCapture("C:\\SS\\video.MOV");
   //IplImage* frame;
   //while (1) {
   //    frame = cvQueryFrame(capture);
   //    if (!frame) break;
   //    cvFlip(frame, frame, 0);
   //    cvShowImage("Example2", frame);
   //    char c = cvWaitKey(33);
   //    if (c == 27) break;
   //}

  /* cvReleaseCapture(&capture);
   cvDestroyWindow("Example2");*/
#pragma endregion

#pragma region AVI Video - Moving Around
  // // Pencereyi oluþtur
  //cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);

  //// Video dosyasýný aç
  //g_capture = cvCreateFileCapture("C:\\SS\\video.MOV");

  //// Video kare sayýsýný al
  //int frames = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);

  //// Eðer video kare sayýsý 0'dan farklý ise trackbar'ý oluþtur
  //if (frames != 0) {
  //    cvCreateTrackbar(
  //        "Position",         // Trackbar'ýn ismi
  //        "Example3",         // Trackbar'ýn bulunduðu pencere ismi
  //        &g_slider_position, // Trackbar'ýn pozisyonu
  //        frames,             // Maksimum deðer (toplam kare sayýsý)
  //        onTrackbarSlide     // Trackbar kaydýrýldýðýnda çalýþacak fonksiyon
  //    );
  //}

  //IplImage* frame;

  //// Video oynatma döngüsü
  //while (true) {
  //    // Trackbar'a göre yeni bir kare al
  //    frame = cvQueryFrame(g_capture);

  //    // Eðer kare alýnamadýysa, video bitti demek
  //    if (!frame) break;

  //    cvFlip(frame, frame, 0);
  //    cvShowImage("Example3", frame);

  //    char c = cvWaitKey(33);
  //    if (c == 27) break;  // ESC tuþuna basýldýðýnda çýk

  //}

  //// Video kaynaðýný serbest býrak
  //cvReleaseCapture(&g_capture);

  //// Pencereyi kapat
  //cvDestroyWindow("Example3");
#pragma endregion

#pragma region A Simple Transformation

  //  void example2_4(IplImage * image);
  //  {
  //      IplImage* image = cvLoadImage("C:\\SS\\Image.jpg");
		// //Create some windows to show the input
		// //and output images in.
		//cvNamedWindow("Example2_4-in", CV_WINDOW_AUTOSIZE);
		//cvNamedWindow("Example2_4-out", CV_WINDOW_AUTOSIZE);
		//// Create a window to show our input image
		//cvShowImage("Example2_4-in", image);
		//// Create an image to hold the smoothed output
		//IplImage* out = cvCreateImage(
		//	cvGetSize(image),
		//	IPL_DEPTH_8U,
		//	3
		//);
		//// Do the smoothing
		//cvSmooth(image, out, CV_GAUSSIAN, 5, 5);
		//// Show the smoothed image in the output window
		//cvShowImage("Example2_4-out", out);
		//// Be tidy
		//cvReleaseImage(&out);
		//// Wait for the user to hit a key, then clean up the windows
		//cvWaitKey(0);
		//cvDestroyWindow("Example2_4-in");
		//cvDestroyWindow("Example2_4-out");

		//
  //  }

#pragma endregion

#pragma region A Not-So-Simple Transformation

//IplImage* Image = cvLoadImage("C:\\SS\\Image.jpg", CV_LOAD_IMAGE_COLOR);
//
//if (!Image) {
//	std::cerr << "Hata: Giriþ görüntüsü yüklenemedi!" << std::endl;
//	return -1;
//}
//
//// Görüntüyü küçült
//IplImage* outputImage = doPyrDown(Image);
//
//if (!outputImage) {
//	cvReleaseImage(&Image);
//	return -1;
//}
//
//// Sonuçlarý göster
//cvShowImage("Orijinal Görüntü", Image);
//cvShowImage("Küçültülmüþ Görüntü", outputImage);
//
//// Kullanýcý bir tuþa basana kadar bekle
//cvWaitKey(0);
//
//// Hafýzayý temizle
//cvReleaseImage(&Image);
//cvReleaseImage(&outputImage);
//cvDestroyAllWindows();

#pragma endregion

#pragma region MyRegion

//IplImage* inputImage = cvLoadImage("C:\\SS\\Image.jpg", CV_LOAD_IMAGE_GRAYSCALE); // Gri tonlama olarak yükle
//
//// Eðer görüntü yüklenemezse hata mesajý göster
//if (!inputImage) {
//	std::cerr << "Hata: Giriþ görüntüsü yüklenemedi!" << std::endl;
//	return -1;
//}
//
//// Canny kenar algýlama iþlemi
//IplImage* outputImage = doCanny(inputImage, 100, 200, 3); // Burada düþük ve yüksek eþik deðerleri ve aperture kullanýlýyor
//
//// Eðer kenar algýlama baþarýsýzsa, bellek temizlenip program sonlandýrýlýr
//if (!outputImage) {
//	cvReleaseImage(&inputImage);
//	return -1;
//}
//
//// Sonuçlarý göster
//cvShowImage("Orijinal Görüntü", inputImage);
//cvShowImage("Canny Kenar Algýlama", outputImage);
//
//// Kullanýcý bir tuþa basana kadar bekle
//cvWaitKey(0);
//
//// Hafýzayý temizle
//cvReleaseImage(&inputImage);
//cvReleaseImage(&outputImage);
//cvDestroyAllWindows();

#pragma endregion

#pragma region Image Pipeline

// // Giriþ görüntüsünü yükle (örneðin 'input.jpg' dosyasýný kullanýyoruz)
//IplImage* inputImage = cvLoadImage("C:\\SS\\Image.jpg", CV_LOAD_IMAGE_GRAYSCALE); // Gri tonlama olarak yükle
//
//// Eðer görüntü yüklenemezse hata mesajý göster
//if (!inputImage) {
//	std::cerr << "Hata: Giriþ görüntüsü yüklenemedi!" << std::endl;
//	return -1;
//}
//
//// Piramit küçültme iþlemi: Görüntüyü iki kez küçült
//IplImage* img1 = doPyrDown(inputImage, IPL_GAUSSIAN_5x5);
//IplImage* img2 = doPyrDown(img1, IPL_GAUSSIAN_5x5);
//
//// Canny kenar algýlama iþlemi
//IplImage* img3 = doCanny(img2, 10, 100, 3); // Burada düþük ve yüksek eþik deðerleri ve aperture kullanýlýyor
//
//// Eðer kenar algýlama baþarýsýzsa, bellek temizlenip program sonlandýrýlýr
//if (!img3) {
//	cvReleaseImage(&inputImage);
//	cvReleaseImage(&img1);
//	cvReleaseImage(&img2);
//	return -1;
//}
//
//// Sonuçlarý göster
//
//cvNamedWindow("Orijinal Görüntü", CV_WINDOW_AUTOSIZE);
//cvShowImage("Orijinal Görüntü", inputImage);
//cvNamedWindow("Piramit Küçültülmüþ 1", CV_WINDOW_AUTOSIZE);
//cvShowImage("Piramit Küçültülmüþ 1", img1);
//cvNamedWindow("Piramit Küçültülmüþ 2", CV_WINDOW_AUTOSIZE);
//cvShowImage("Piramit Küçültülmüþ 2", img2);
//cvNamedWindow("Canny Kenar Algýlama", CV_WINDOW_AUTOSIZE);
//cvShowImage("Canny Kenar Algýlama", img3);
//
//// Kullanýcý bir tuþa basana kadar bekle
//cvWaitKey(0);
//
//// Hafýzayý temizle
//cvReleaseImage(&inputImage);
//cvReleaseImage(&img1);
//cvReleaseImage(&img2);
//cvReleaseImage(&img3);
//
//cvDestroyAllWindows();
#pragma endregion

#pragma region Kamera
//
//CvCapture* capture;
//capture = cvCreateCameraCapture(0);
//
//assert(capture != NULL);
//IplImage* frame;
//
//while (true)
//{
//	frame = cvQueryFrame(capture);
//	if (!frame) break;
//	cvShowImage("Kamera Görüntüsü", frame);
//	char c = cvWaitKey(33);
//	if (c == 27) break;
//}
//
//cvReleaseCapture(&capture);
//cvDestroyAllWindows();

#pragma endregion

#pragma region MyRegion

//CvCapture* capture = cvCreateCameraCapture(0);  // 0, varsayýlan kamerayý seçer
//if (!capture) {
//    printf("Kamera açýlýrken bir hata oluþtu!\n");
//    return -1;  // Kamera açýlmazsa hata döndür
//}
//
//// FPS bilgisi
//double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
//if (fps == 0) {
//    fps = 30.0;  // FPS deðeri alýnamazsa varsayýlan bir deðer kullan
//}
//
//// Video boyutlarý
//CvSize size = cvSize(
//    (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
//    (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
//);
//
//// Çýkýþ video dosyasýný oluþtur
//CvVideoWriter* writer = cvCreateVideoWriter("output_video.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
//if (!writer) {
//    printf("Video yazýcýsý oluþturulurken bir hata oluþtu!\n");
//    cvReleaseCapture(&capture);
//    return -1;  // Video yazýcýsý oluþturulamazsa hata döndür
//}
//
//// Gri tonlamalý kare için boþ bir görüntü oluþtur
//IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 1);
//if (!logpolar_frame) {
//    printf("Log-polar görüntüsü oluþturulurken bir hata oluþtu!\n");
//    cvReleaseVideoWriter(&writer);
//    cvReleaseCapture(&capture);
//    return -1;
//}
//
//// Videoyu iþlemek için döngü
//IplImage* bgr_frame = NULL;
//while ((bgr_frame = cvQueryFrame(capture)) != NULL) {
//    if (!bgr_frame) {
//        printf("Kare alýnýrken bir hata oluþtu!\n");
//        break;  // Kare alýnamazsa döngüyü sonlandýr
//    }
//
//    // Log-polar dönüþümünü uygula
//    cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame->width / 2.0f, bgr_frame->height / 2.0f), 40, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
//
//    // Gri tonlamalý kareyi videoya yaz
//    cvWriteFrame(writer, logpolar_frame);
//}
//
//
//// Video yazýcýyý serbest býrak
//cvReleaseVideoWriter(&writer);
//// Gri tonlama görüntüsünü serbest býrak
//cvReleaseImage(&logpolar_frame);
//// Kamera baðlantýsýný serbest býrak
//cvReleaseCapture(&capture);
//
//printf("Video baþarýyla oluþturuldu!\n");
#pragma endregion

#pragma region Histogram

    //// Görüntüyü yükle
    //IplImage* image = cvLoadImage("C:\\SS\\indir.jpg", 1);
    //if (!image) {
    //    printf("Hata: Görüntü yüklenemedi! Dosya yolunu kontrol et.\n");
    //    return -1;
    //}

    //// Gri seviyeye çevir
    //IplImage* gray = cvCreateImage(cvGetSize(image), 8, 1);
    //cvCvtColor(image, gray, CV_BGR2GRAY);

    //// Histogram parametreleri
    //int hist_size = 256;
    //float range[] = { 0, 256 };
    //float* hist_range[] = { range };  // Buradaki hata düzeltildi!
    //CvHistogram* hist = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);

    //// Histogramý hesapla
    //cvCalcHist(&gray, hist, 0, NULL);

    //// Histogramý görselleþtir
    //int hist_w = 512, hist_h = 400;
    //int bin_w = cvRound((double)hist_w / hist_size);

    //IplImage* hist_img = cvCreateImage(cvSize(hist_w, hist_h), 8, 1);
    //cvZero(hist_img);

    //// Histogramý normalize et
    //cvNormalizeHist(hist, 1);

    //// Histogramý çiz
    //for (int i = 1; i < hist_size; i++) {
    //    cvLine(hist_img,
    //        cvPoint(bin_w * (i - 1), hist_h - cvRound(cvQueryHistValue_1D(hist, i - 1) * hist_h)),
    //        cvPoint(bin_w * i, hist_h - cvRound(cvQueryHistValue_1D(hist, i) * hist_h)),
    //        cvScalar(255, 255, 255), 2, 8, 0);
    //}

    //// Histogramý göster
    //cvNamedWindow("Histogram", CV_WINDOW_AUTOSIZE);
    //cvShowImage("Histogram", hist_img);
    //cvWaitKey(0);

    //// Belleði temizle
    //cvReleaseImage(&image);
    //cvReleaseImage(&gray);
    //cvReleaseImage(&hist_img);
    //cvReleaseHist(&hist);

    //// Pencereleri kapat
    //cvDestroyAllWindows();
 
#pragma endregion

#pragma region Compare Histogram

    /*// Ýlk görüntüyü yükle
    IplImage* image1 = cvLoadImage("C:\\SS\\Image.jpg", 1);
    if (!image1) {
        printf("Hata: 'Image1.jpg' yüklenemedi! Dosya yolunu kontrol et.\n");
        return -1;
    }

    // Ýkinci görüntüyü yükle
    IplImage* image2 = cvLoadImage("C:\\SS\\indir.jpg", 1);
    if (!image2) {
        printf("Hata: 'Image2.jpg' yüklenemedi! Dosya yolunu kontrol et.\n");
        return -1;
    }

    // Gri seviyeye çevir
    IplImage* gray1 = cvCreateImage(cvGetSize(image1), 8, 1);
    cvCvtColor(image1, gray1, CV_BGR2GRAY);
    IplImage* gray2 = cvCreateImage(cvGetSize(image2), 8, 1);
    cvCvtColor(image2, gray2, CV_BGR2GRAY);

    // Histogram parametreleri
    int hist_size = 256;
    float range[] = { 0, 256 };
    float* hist_range[] = { range };

    // Histogramlarý yarat
    CvHistogram* hist1 = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);
    CvHistogram* hist2 = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);

    // Histogramlarý hesapla
    cvCalcHist(&gray1, hist1, 0, NULL);
    cvCalcHist(&gray2, hist2, 0, NULL);

    // Histogramlarý karþýlaþtýr
    double similarity = cvCompareHist(hist1, hist2, CV_COMP_CORREL);  // Korelasyon kullanýlarak benzerlik hesaplanýr.
    printf("Histogramlar arasýndaki benzerlik: %f\n", similarity);

    // Görüntüleri ve histogramlarý göster
    cvNamedWindow("Gri Görüntü 1", CV_WINDOW_AUTOSIZE);
    cvShowImage("Gri Görüntü 1", gray1);

    cvNamedWindow("Gri Görüntü 2", CV_WINDOW_AUTOSIZE);
    cvShowImage("Gri Görüntü 2", gray2);

    // Bekle
    cvWaitKey(0);

    // Belleði temizle
    cvReleaseImage(&image1);
    cvReleaseImage(&image2);
    cvReleaseImage(&gray1);
    cvReleaseImage(&gray2);
    cvReleaseHist(&hist1);
    cvReleaseHist(&hist2);

    // Pencereleri kapat
    cvDestroyAllWindows();

    // Histogram görselleþtirme ekleyelim
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / hist_size);

    IplImage* hist1 = cvCreateImage(cvSize(hist_w, hist_h), 8, 1);
    IplImage* hist2 = cvCreateImage(cvSize(hist_w, hist_h), 8, 1);
    cvZero(hist1);
    cvZero(hist2);

    // Histogramlarý normalize et
    cvNormalizeHist(hist1, 1);
    cvNormalizeHist(hist2, 1);

    // Histogramlarý çiz
    for (int i = 1; i < hist_size; i++) {
        cvLine(hist1,
            cvPoint(bin_w * (i - 1), hist_h - cvRound(cvQueryHistValue_1D(hist1, i - 1) * hist_h)),
            cvPoint(bin_w * i, hist_h - cvRound(cvQueryHistValue_1D(hist1, i) * hist_h)),
            cvScalar(255, 0, 0), 2, 8, 0); // Mavi renk histogram1 için

        cvLine(hist2,
            cvPoint(bin_w * (i - 1), hist_h - cvRound(cvQueryHistValue_1D(hist2, i - 1) * hist_h)),
            cvPoint(bin_w * i, hist_h - cvRound(cvQueryHistValue_1D(hist2, i) * hist_h)),
            cvScalar(0, 255, 0), 2, 8, 0); // Yeþil renk histogram2 için
    }

    // Histogramlarý göster
    cvNamedWindow("Histogram 1", CV_WINDOW_AUTOSIZE);
    cvShowImage("Histogram 1", hist1);
    cvNamedWindow("Histogram 2", CV_WINDOW_AUTOSIZE);
    cvShowImage("Histogram 2", hist2);
    cvWaitKey(0);*/

#pragma endregion

#pragma region Compare Histogram 2

//    // Ýlk görüntüyü yükle
//IplImage* image1 = cvLoadImage("C:\\SS\\Image.jpg", 1);
//if (!image1) {
//    printf("Hata: 'Image1.jpg' yüklenemedi! Dosya yolunu kontrol et.\n");
//    return -1;
//}
//
//// Ýkinci görüntüyü yükle
//IplImage* image2 = cvLoadImage("C:\\SS\\image2.jpg", 1);
//if (!image2) {
//    printf("Hata: 'Image2.jpg' yüklenemedi! Dosya yolunu kontrol et.\n");
//    return -1;
//}
//
//// Gri seviyeye çevir
//IplImage* gray1 = cvCreateImage(cvGetSize(image1), 8, 1);
//cvCvtColor(image1, gray1, CV_BGR2GRAY);
//IplImage* gray2 = cvCreateImage(cvGetSize(image2), 8, 1);
//cvCvtColor(image2, gray2, CV_BGR2GRAY);
//
//// Histogram parametreleri
//int hist_size = 256;
//float range[] = { 0, 256 };
//float* hist_range[] = { range };
//
//// Histogramlarý yarat
//CvHistogram* hist1 = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);
//CvHistogram* hist2 = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);
//
//// Histogramlarý hesapla
//cvCalcHist(&gray1, hist1, 0, NULL);
//cvCalcHist(&gray2, hist2, 0, NULL);
//
//// Histogramlarý karþýlaþtýr
//double similarity = cvCompareHist(hist1, hist2, CV_COMP_CORREL);  // Korelasyon kullanýlarak benzerlik hesaplanýr.
//printf("Histogramlar arasýndaki benzerlik: %f\n", similarity);
//
//// Histogram görselleþtirme ekleyelim
//int hist_w = 512, hist_h = 400;
//int bin_w = cvRound((double)hist_w / hist_size);
//
//IplImage* hist_img1 = cvCreateImage(cvSize(hist_w, hist_h), 8, 3);  // 3 kanal RGB görüntü
//IplImage* hist_img2 = cvCreateImage(cvSize(hist_w, hist_h), 8, 3);  // 3 kanal RGB görüntü
//cvZero(hist_img1);
//cvZero(hist_img2);
//
//// Histogramlarý normalize et
//cvNormalizeHist(hist1, 1);
//cvNormalizeHist(hist2, 1);
//
//// Histogramlarý çiz
//for (int i = 1; i < hist_size; i++) {
//    // Histogram1 çizimi
//    int height1 = cvRound(cvQueryHistValue_1D(hist1, i) * hist_h);
//    int height2 = cvRound(cvQueryHistValue_1D(hist2, i) * hist_h);
//
//    // Histogram1 için mavi çizgi
//    cvLine(hist_img1,
//        cvPoint(bin_w * (i - 1), hist_h - height1),
//        cvPoint(bin_w * i, hist_h - height1),
//        cvScalar(255, 0, 0), 2, 8, 0);  // Mavi renk
//
//    // Histogram2 için yeþil çizgi
//    cvLine(hist_img2,
//        cvPoint(bin_w * (i - 1), hist_h - height2),
//        cvPoint(bin_w * i, hist_h - height2),
//        cvScalar(0, 255, 0), 2, 8, 0);  // Yeþil renk
//}
//
//// Görüntüleri ve histogramlarý göster
//cvNamedWindow("Gri Görüntü 1", CV_WINDOW_AUTOSIZE);
//cvShowImage("Gri Görüntü 1", gray1);
//
//cvNamedWindow("Gri Görüntü 2", CV_WINDOW_AUTOSIZE);
//cvShowImage("Gri Görüntü 2", gray2);
//
//// Histogramlarý göster
//cvNamedWindow("Histogram 1", CV_WINDOW_AUTOSIZE);
//cvShowImage("Histogram 1", hist_img1);
//
//cvNamedWindow("Histogram 2", CV_WINDOW_AUTOSIZE);
//cvShowImage("Histogram 2", hist_img2);
//
//// Bekle
//cvWaitKey(0);
//
//// Belleði temizle
//cvReleaseImage(&image1);
//cvReleaseImage(&image2);
//cvReleaseImage(&gray1);
//cvReleaseImage(&gray2);
//cvReleaseImage(&hist_img1);
//cvReleaseImage(&hist_img2);
//cvReleaseHist(&hist1);
//cvReleaseHist(&hist2);
//
//// Pencereleri kapat
//cvDestroyAllWindows();



#pragma endregion

#pragma region Histogram Equalization
//// Görüntüyü yükle
//IplImage* image = cvLoadImage("C:\\SS\\image2.jpg", 1);
//
//// Gri tonlamaya çevir
//IplImage* gray = cvCreateImage(cvGetSize(image), 8, 1);
//cvCvtColor(image, gray, CV_BGR2GRAY);
//
//// Histogram eþitleme
//IplImage* equalized = cvCreateImage(cvGetSize(image), 8, 1);
//cvEqualizeHist(gray, equalized);
//
//// Kenar tespiti (Canny)
//IplImage* edges = cvCreateImage(cvGetSize(image), 8, 1);
//cvCanny(equalized, edges, 50, 150, 3);
//
//// Sonuçlarý göster
//cvNamedWindow("Histogram Equalized", CV_WINDOW_AUTOSIZE);
//cvShowImage("Histogram Equalized", equalized);
//
//cvNamedWindow("Edge Detection", CV_WINDOW_AUTOSIZE);
//cvShowImage("Edge Detection", edges);
//
//// Bekle ve temizle
//cvWaitKey(0);
//cvReleaseImage(&image);
//cvReleaseImage(&gray);
//cvReleaseImage(&equalized);
//cvReleaseImage(&edges);
//cvDestroyAllWindows();

#pragma endregion

#pragma region Histogram Thresholding

//// Görüntüyü yükle
//IplImage* image = cvLoadImage("C:\\SS\\image2.jpg", 1);
//
//// Gri tonlamaya çevir
//IplImage* gray = cvCreateImage(cvGetSize(image), 8, 1);
//cvCvtColor(image, gray, CV_BGR2GRAY);
//
//// Otsu ile eþikleme
//IplImage* thresholded = cvCreateImage(cvGetSize(image), 8, 1);
//cvThreshold(gray, thresholded, 0, 255, CV_THRESH_BINARY + CV_THRESH_OTSU);
//
//// Kenar tespiti
//IplImage* edges = cvCreateImage(cvGetSize(image), 8, 1);
//cvCanny(thresholded, edges, 50, 150, 3);
//
//// Sonuçlarý göster
//cvNamedWindow("Thresholded Image", CV_WINDOW_AUTOSIZE);
//cvShowImage("Thresholded Image", thresholded);
//
//cvNamedWindow("Edge Detection", CV_WINDOW_AUTOSIZE);
//cvShowImage("Edge Detection", edges);
//
//// Bekle ve temizle
//cvWaitKey(0);
//cvReleaseImage(&image);
//cvReleaseImage(&gray);
//cvReleaseImage(&thresholded);
//cvReleaseImage(&edges);
//cvDestroyAllWindows();


#pragma endregion

#pragma region Back Projection

    /*// Görüntüleri yükle
    IplImage* image = cvLoadImage("C:\\SS\\Image.jpg", CV_LOAD_IMAGE_COLOR);
    IplImage* template_img = cvLoadImage("C:\\SS\\image2.jpg", CV_LOAD_IMAGE_COLOR);

    // Görüntüleri gri tonlamaya dönüþtür
    IplImage* gray_image = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
    IplImage* gray_template = cvCreateImage(cvGetSize(template_img), IPL_DEPTH_8U, 1);

    cvCvtColor(image, gray_image, CV_BGR2GRAY);
    cvCvtColor(template_img, gray_template, CV_BGR2GRAY);

    // Histogram hesaplama için gerekli parametreler
    int hist_size = 256;
    float range[] = { 0, 256 };
    float* hist_range[] = { range };

    // Template'in histogramýný hesapla
    CvHistogram* hist = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);
    cvCalcHist(&gray_template, hist, 0, NULL);

    // Histogramlarý normalize et
    cvNormalizeHist(hist, 1.0); // Histogram normalizasyonu

    // Back projection
    IplImage* back_project = cvCreateImage(cvGetSize(gray_image), IPL_DEPTH_8U, 1);
    cvCalcBackProject(&gray_image, back_project, hist);

    // Back projection'ý görselleþtir
    cvNamedWindow("Back Projection", CV_WINDOW_AUTOSIZE);
    cvShowImage("Back Projection", back_project);
    cvWaitKey(0);

    // Belleði temizle
    cvReleaseImage(&image);
    cvReleaseImage(&template_img);
    cvReleaseImage(&gray_image);
    cvReleaseImage(&gray_template);
    cvReleaseImage(&back_project);
    cvReleaseHist(&hist);

    cvDestroyAllWindows();*/

#pragma endregion

#pragma region Template Matching


    // Görüntüleri yükle
    IplImage* image = cvLoadImage("C:\\SS\\indir.jpg", CV_LOAD_IMAGE_COLOR);
    IplImage* template_img = cvLoadImage("C:\\SS\\image2.jpg", CV_LOAD_IMAGE_COLOR);

    // Görüntüleri gri tonlamaya dönüþtür
    IplImage* gray_image = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
    IplImage* gray_template = cvCreateImage(cvGetSize(template_img), IPL_DEPTH_8U, 1);

    cvCvtColor(image, gray_image, CV_BGR2GRAY);
    cvCvtColor(template_img, gray_template, CV_BGR2GRAY);

    // Template matching iþlemi için uygun bir alan (MatchTemplate)
    IplImage* result = cvCreateImage(cvGetSize(gray_image), IPL_DEPTH_32F, 1);
    cvMatchTemplate(gray_image, gray_template, result, CV_TM_CCOEFF_NORMED);

    // Sonuçlarý görselleþtir
    double minVal, maxVal;
    CvPoint minLoc, maxLoc;
    cvMinMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, NULL);

    // En yüksek benzerlik noktasýný iþaretle
    cvRectangle(image, maxLoc, cvPoint(maxLoc.x + template_img->width, maxLoc.y + template_img->height), CV_RGB(0, 255, 0), 2);

    // Template matching sonrasýný görselleþtir
    cvNamedWindow("Template Matching", CV_WINDOW_AUTOSIZE);
    cvShowImage("Template Matching", image);
    cvWaitKey(0);

    // Belleði temizle
    cvReleaseImage(&image);
    cvReleaseImage(&template_img);
    cvReleaseImage(&gray_image);
    cvReleaseImage(&gray_template);
    cvReleaseImage(&result);

    cvDestroyAllWindows();

     
#pragma endregion

    return 0;

}

