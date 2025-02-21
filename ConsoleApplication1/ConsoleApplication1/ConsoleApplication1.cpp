#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <cassert>
#include <opencv2/imgproc/imgproc_c.h>  i
#include <opencv2/highgui/highgui_c.h>

//int g_slider_position = 0;  // Trackbar'�n pozisyonu
//CvCapture* g_capture = NULL;  // Video kayna��n� tutacak
//
//// Trackbar kayd�r�ld���nda bu fonksiyon �al��acak
//void onTrackbarSlide(int pos)
//{
//   // Trackbar pozisyonuna g�re video karesine git
//    cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
//}

IplImage* doPyrDown(IplImage* in, int filter = IPL_GAUSSIAN_5x5) {
	assert(in->width % 2 == 0 && in->height % 2 == 0); // Giri� g�r�nt�s�n�n �ift boyutlarda oldu�undan emin ol

	IplImage* out = cvCreateImage(cvSize(in->width / 2, in->height / 2), in->depth, in->nChannels);
	cvPyrDown(in, out, filter);
	return out;
}

	IplImage* doCanny(IplImage * in, double lowThresh, double highThresh, double aperture) {
		if (in->nChannels != 1) {
			std::cerr << "Hata: Canny yaln�zca gri tonlama (tek kanal) g�r�nt�lerini i�ler!" << std::endl;
			return nullptr;
		}

		CvSize size = cvGetSize(in); // Boyutlar� al
		IplImage* out = cvCreateImage(size, IPL_DEPTH_8U, 1); // ��kt� g�r�nt�s�n� olu�tur

		cvCanny(in, out, lowThresh, highThresh, aperture); // Canny kenar alg�lama

		return out; // ��k�� g�r�nt�s�n� d�nd�r
	}


int main(int argc, char** argv) {

#pragma region Display a Picture
    // Resmi renkli olarak y�kle
   //IplImage* img = cvLoadImage("C:\\SS\\Image.jpg");

   //// Pencereyi olu�tur
   //cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);

   //// Resmi pencereye g�ster
   //cvShowImage("Example1", img);

   //// Bir tu�a bas�lana kadar bekle
   //cvWaitKey(0);

   //// Kaynaklar� serbest b�rak ve pencereyi kapat
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
  // // Pencereyi olu�tur
  //cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);

  //// Video dosyas�n� a�
  //g_capture = cvCreateFileCapture("C:\\SS\\video.MOV");

  //// Video kare say�s�n� al
  //int frames = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);

  //// E�er video kare say�s� 0'dan farkl� ise trackbar'� olu�tur
  //if (frames != 0) {
  //    cvCreateTrackbar(
  //        "Position",         // Trackbar'�n ismi
  //        "Example3",         // Trackbar'�n bulundu�u pencere ismi
  //        &g_slider_position, // Trackbar'�n pozisyonu
  //        frames,             // Maksimum de�er (toplam kare say�s�)
  //        onTrackbarSlide     // Trackbar kayd�r�ld���nda �al��acak fonksiyon
  //    );
  //}

  //IplImage* frame;

  //// Video oynatma d�ng�s�
  //while (true) {
  //    // Trackbar'a g�re yeni bir kare al
  //    frame = cvQueryFrame(g_capture);

  //    // E�er kare al�namad�ysa, video bitti demek
  //    if (!frame) break;

  //    cvFlip(frame, frame, 0);
  //    cvShowImage("Example3", frame);

  //    char c = cvWaitKey(33);
  //    if (c == 27) break;  // ESC tu�una bas�ld���nda ��k

  //}

  //// Video kayna��n� serbest b�rak
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
//	std::cerr << "Hata: Giri� g�r�nt�s� y�klenemedi!" << std::endl;
//	return -1;
//}
//
//// G�r�nt�y� k���lt
//IplImage* outputImage = doPyrDown(Image);
//
//if (!outputImage) {
//	cvReleaseImage(&Image);
//	return -1;
//}
//
//// Sonu�lar� g�ster
//cvShowImage("Orijinal G�r�nt�", Image);
//cvShowImage("K���lt�lm�� G�r�nt�", outputImage);
//
//// Kullan�c� bir tu�a basana kadar bekle
//cvWaitKey(0);
//
//// Haf�zay� temizle
//cvReleaseImage(&Image);
//cvReleaseImage(&outputImage);
//cvDestroyAllWindows();

#pragma endregion

#pragma region MyRegion

//IplImage* inputImage = cvLoadImage("C:\\SS\\Image.jpg", CV_LOAD_IMAGE_GRAYSCALE); // Gri tonlama olarak y�kle
//
//// E�er g�r�nt� y�klenemezse hata mesaj� g�ster
//if (!inputImage) {
//	std::cerr << "Hata: Giri� g�r�nt�s� y�klenemedi!" << std::endl;
//	return -1;
//}
//
//// Canny kenar alg�lama i�lemi
//IplImage* outputImage = doCanny(inputImage, 100, 200, 3); // Burada d���k ve y�ksek e�ik de�erleri ve aperture kullan�l�yor
//
//// E�er kenar alg�lama ba�ar�s�zsa, bellek temizlenip program sonland�r�l�r
//if (!outputImage) {
//	cvReleaseImage(&inputImage);
//	return -1;
//}
//
//// Sonu�lar� g�ster
//cvShowImage("Orijinal G�r�nt�", inputImage);
//cvShowImage("Canny Kenar Alg�lama", outputImage);
//
//// Kullan�c� bir tu�a basana kadar bekle
//cvWaitKey(0);
//
//// Haf�zay� temizle
//cvReleaseImage(&inputImage);
//cvReleaseImage(&outputImage);
//cvDestroyAllWindows();

#pragma endregion

#pragma region Image Pipeline

// // Giri� g�r�nt�s�n� y�kle (�rne�in 'input.jpg' dosyas�n� kullan�yoruz)
//IplImage* inputImage = cvLoadImage("C:\\SS\\Image.jpg", CV_LOAD_IMAGE_GRAYSCALE); // Gri tonlama olarak y�kle
//
//// E�er g�r�nt� y�klenemezse hata mesaj� g�ster
//if (!inputImage) {
//	std::cerr << "Hata: Giri� g�r�nt�s� y�klenemedi!" << std::endl;
//	return -1;
//}
//
//// Piramit k���ltme i�lemi: G�r�nt�y� iki kez k���lt
//IplImage* img1 = doPyrDown(inputImage, IPL_GAUSSIAN_5x5);
//IplImage* img2 = doPyrDown(img1, IPL_GAUSSIAN_5x5);
//
//// Canny kenar alg�lama i�lemi
//IplImage* img3 = doCanny(img2, 10, 100, 3); // Burada d���k ve y�ksek e�ik de�erleri ve aperture kullan�l�yor
//
//// E�er kenar alg�lama ba�ar�s�zsa, bellek temizlenip program sonland�r�l�r
//if (!img3) {
//	cvReleaseImage(&inputImage);
//	cvReleaseImage(&img1);
//	cvReleaseImage(&img2);
//	return -1;
//}
//
//// Sonu�lar� g�ster
//
//cvNamedWindow("Orijinal G�r�nt�", CV_WINDOW_AUTOSIZE);
//cvShowImage("Orijinal G�r�nt�", inputImage);
//cvNamedWindow("Piramit K���lt�lm�� 1", CV_WINDOW_AUTOSIZE);
//cvShowImage("Piramit K���lt�lm�� 1", img1);
//cvNamedWindow("Piramit K���lt�lm�� 2", CV_WINDOW_AUTOSIZE);
//cvShowImage("Piramit K���lt�lm�� 2", img2);
//cvNamedWindow("Canny Kenar Alg�lama", CV_WINDOW_AUTOSIZE);
//cvShowImage("Canny Kenar Alg�lama", img3);
//
//// Kullan�c� bir tu�a basana kadar bekle
//cvWaitKey(0);
//
//// Haf�zay� temizle
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
//	cvShowImage("Kamera G�r�nt�s�", frame);
//	char c = cvWaitKey(33);
//	if (c == 27) break;
//}
//
//cvReleaseCapture(&capture);
//cvDestroyAllWindows();

#pragma endregion

#pragma region MyRegion

//CvCapture* capture = cvCreateCameraCapture(0);  // 0, varsay�lan kameray� se�er
//if (!capture) {
//    printf("Kamera a��l�rken bir hata olu�tu!\n");
//    return -1;  // Kamera a��lmazsa hata d�nd�r
//}
//
//// FPS bilgisi
//double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
//if (fps == 0) {
//    fps = 30.0;  // FPS de�eri al�namazsa varsay�lan bir de�er kullan
//}
//
//// Video boyutlar�
//CvSize size = cvSize(
//    (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
//    (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
//);
//
//// ��k�� video dosyas�n� olu�tur
//CvVideoWriter* writer = cvCreateVideoWriter("output_video.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
//if (!writer) {
//    printf("Video yaz�c�s� olu�turulurken bir hata olu�tu!\n");
//    cvReleaseCapture(&capture);
//    return -1;  // Video yaz�c�s� olu�turulamazsa hata d�nd�r
//}
//
//// Gri tonlamal� kare i�in bo� bir g�r�nt� olu�tur
//IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 1);
//if (!logpolar_frame) {
//    printf("Log-polar g�r�nt�s� olu�turulurken bir hata olu�tu!\n");
//    cvReleaseVideoWriter(&writer);
//    cvReleaseCapture(&capture);
//    return -1;
//}
//
//// Videoyu i�lemek i�in d�ng�
//IplImage* bgr_frame = NULL;
//while ((bgr_frame = cvQueryFrame(capture)) != NULL) {
//    if (!bgr_frame) {
//        printf("Kare al�n�rken bir hata olu�tu!\n");
//        break;  // Kare al�namazsa d�ng�y� sonland�r
//    }
//
//    // Log-polar d�n���m�n� uygula
//    cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame->width / 2.0f, bgr_frame->height / 2.0f), 40, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
//
//    // Gri tonlamal� kareyi videoya yaz
//    cvWriteFrame(writer, logpolar_frame);
//}
//
//
//// Video yaz�c�y� serbest b�rak
//cvReleaseVideoWriter(&writer);
//// Gri tonlama g�r�nt�s�n� serbest b�rak
//cvReleaseImage(&logpolar_frame);
//// Kamera ba�lant�s�n� serbest b�rak
//cvReleaseCapture(&capture);
//
//printf("Video ba�ar�yla olu�turuldu!\n");
#pragma endregion

#pragma region Histogram

    //// G�r�nt�y� y�kle
    //IplImage* image = cvLoadImage("C:\\SS\\indir.jpg", 1);
    //if (!image) {
    //    printf("Hata: G�r�nt� y�klenemedi! Dosya yolunu kontrol et.\n");
    //    return -1;
    //}

    //// Gri seviyeye �evir
    //IplImage* gray = cvCreateImage(cvGetSize(image), 8, 1);
    //cvCvtColor(image, gray, CV_BGR2GRAY);

    //// Histogram parametreleri
    //int hist_size = 256;
    //float range[] = { 0, 256 };
    //float* hist_range[] = { range };  // Buradaki hata d�zeltildi!
    //CvHistogram* hist = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);

    //// Histogram� hesapla
    //cvCalcHist(&gray, hist, 0, NULL);

    //// Histogram� g�rselle�tir
    //int hist_w = 512, hist_h = 400;
    //int bin_w = cvRound((double)hist_w / hist_size);

    //IplImage* hist_img = cvCreateImage(cvSize(hist_w, hist_h), 8, 1);
    //cvZero(hist_img);

    //// Histogram� normalize et
    //cvNormalizeHist(hist, 1);

    //// Histogram� �iz
    //for (int i = 1; i < hist_size; i++) {
    //    cvLine(hist_img,
    //        cvPoint(bin_w * (i - 1), hist_h - cvRound(cvQueryHistValue_1D(hist, i - 1) * hist_h)),
    //        cvPoint(bin_w * i, hist_h - cvRound(cvQueryHistValue_1D(hist, i) * hist_h)),
    //        cvScalar(255, 255, 255), 2, 8, 0);
    //}

    //// Histogram� g�ster
    //cvNamedWindow("Histogram", CV_WINDOW_AUTOSIZE);
    //cvShowImage("Histogram", hist_img);
    //cvWaitKey(0);

    //// Belle�i temizle
    //cvReleaseImage(&image);
    //cvReleaseImage(&gray);
    //cvReleaseImage(&hist_img);
    //cvReleaseHist(&hist);

    //// Pencereleri kapat
    //cvDestroyAllWindows();
 
#pragma endregion

#pragma region Compare Histogram

    /*// �lk g�r�nt�y� y�kle
    IplImage* image1 = cvLoadImage("C:\\SS\\Image.jpg", 1);
    if (!image1) {
        printf("Hata: 'Image1.jpg' y�klenemedi! Dosya yolunu kontrol et.\n");
        return -1;
    }

    // �kinci g�r�nt�y� y�kle
    IplImage* image2 = cvLoadImage("C:\\SS\\indir.jpg", 1);
    if (!image2) {
        printf("Hata: 'Image2.jpg' y�klenemedi! Dosya yolunu kontrol et.\n");
        return -1;
    }

    // Gri seviyeye �evir
    IplImage* gray1 = cvCreateImage(cvGetSize(image1), 8, 1);
    cvCvtColor(image1, gray1, CV_BGR2GRAY);
    IplImage* gray2 = cvCreateImage(cvGetSize(image2), 8, 1);
    cvCvtColor(image2, gray2, CV_BGR2GRAY);

    // Histogram parametreleri
    int hist_size = 256;
    float range[] = { 0, 256 };
    float* hist_range[] = { range };

    // Histogramlar� yarat
    CvHistogram* hist1 = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);
    CvHistogram* hist2 = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);

    // Histogramlar� hesapla
    cvCalcHist(&gray1, hist1, 0, NULL);
    cvCalcHist(&gray2, hist2, 0, NULL);

    // Histogramlar� kar��la�t�r
    double similarity = cvCompareHist(hist1, hist2, CV_COMP_CORREL);  // Korelasyon kullan�larak benzerlik hesaplan�r.
    printf("Histogramlar aras�ndaki benzerlik: %f\n", similarity);

    // G�r�nt�leri ve histogramlar� g�ster
    cvNamedWindow("Gri G�r�nt� 1", CV_WINDOW_AUTOSIZE);
    cvShowImage("Gri G�r�nt� 1", gray1);

    cvNamedWindow("Gri G�r�nt� 2", CV_WINDOW_AUTOSIZE);
    cvShowImage("Gri G�r�nt� 2", gray2);

    // Bekle
    cvWaitKey(0);

    // Belle�i temizle
    cvReleaseImage(&image1);
    cvReleaseImage(&image2);
    cvReleaseImage(&gray1);
    cvReleaseImage(&gray2);
    cvReleaseHist(&hist1);
    cvReleaseHist(&hist2);

    // Pencereleri kapat
    cvDestroyAllWindows();

    // Histogram g�rselle�tirme ekleyelim
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double)hist_w / hist_size);

    IplImage* hist1 = cvCreateImage(cvSize(hist_w, hist_h), 8, 1);
    IplImage* hist2 = cvCreateImage(cvSize(hist_w, hist_h), 8, 1);
    cvZero(hist1);
    cvZero(hist2);

    // Histogramlar� normalize et
    cvNormalizeHist(hist1, 1);
    cvNormalizeHist(hist2, 1);

    // Histogramlar� �iz
    for (int i = 1; i < hist_size; i++) {
        cvLine(hist1,
            cvPoint(bin_w * (i - 1), hist_h - cvRound(cvQueryHistValue_1D(hist1, i - 1) * hist_h)),
            cvPoint(bin_w * i, hist_h - cvRound(cvQueryHistValue_1D(hist1, i) * hist_h)),
            cvScalar(255, 0, 0), 2, 8, 0); // Mavi renk histogram1 i�in

        cvLine(hist2,
            cvPoint(bin_w * (i - 1), hist_h - cvRound(cvQueryHistValue_1D(hist2, i - 1) * hist_h)),
            cvPoint(bin_w * i, hist_h - cvRound(cvQueryHistValue_1D(hist2, i) * hist_h)),
            cvScalar(0, 255, 0), 2, 8, 0); // Ye�il renk histogram2 i�in
    }

    // Histogramlar� g�ster
    cvNamedWindow("Histogram 1", CV_WINDOW_AUTOSIZE);
    cvShowImage("Histogram 1", hist1);
    cvNamedWindow("Histogram 2", CV_WINDOW_AUTOSIZE);
    cvShowImage("Histogram 2", hist2);
    cvWaitKey(0);*/

#pragma endregion

#pragma region Compare Histogram 2

//    // �lk g�r�nt�y� y�kle
//IplImage* image1 = cvLoadImage("C:\\SS\\Image.jpg", 1);
//if (!image1) {
//    printf("Hata: 'Image1.jpg' y�klenemedi! Dosya yolunu kontrol et.\n");
//    return -1;
//}
//
//// �kinci g�r�nt�y� y�kle
//IplImage* image2 = cvLoadImage("C:\\SS\\image2.jpg", 1);
//if (!image2) {
//    printf("Hata: 'Image2.jpg' y�klenemedi! Dosya yolunu kontrol et.\n");
//    return -1;
//}
//
//// Gri seviyeye �evir
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
//// Histogramlar� yarat
//CvHistogram* hist1 = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);
//CvHistogram* hist2 = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);
//
//// Histogramlar� hesapla
//cvCalcHist(&gray1, hist1, 0, NULL);
//cvCalcHist(&gray2, hist2, 0, NULL);
//
//// Histogramlar� kar��la�t�r
//double similarity = cvCompareHist(hist1, hist2, CV_COMP_CORREL);  // Korelasyon kullan�larak benzerlik hesaplan�r.
//printf("Histogramlar aras�ndaki benzerlik: %f\n", similarity);
//
//// Histogram g�rselle�tirme ekleyelim
//int hist_w = 512, hist_h = 400;
//int bin_w = cvRound((double)hist_w / hist_size);
//
//IplImage* hist_img1 = cvCreateImage(cvSize(hist_w, hist_h), 8, 3);  // 3 kanal RGB g�r�nt�
//IplImage* hist_img2 = cvCreateImage(cvSize(hist_w, hist_h), 8, 3);  // 3 kanal RGB g�r�nt�
//cvZero(hist_img1);
//cvZero(hist_img2);
//
//// Histogramlar� normalize et
//cvNormalizeHist(hist1, 1);
//cvNormalizeHist(hist2, 1);
//
//// Histogramlar� �iz
//for (int i = 1; i < hist_size; i++) {
//    // Histogram1 �izimi
//    int height1 = cvRound(cvQueryHistValue_1D(hist1, i) * hist_h);
//    int height2 = cvRound(cvQueryHistValue_1D(hist2, i) * hist_h);
//
//    // Histogram1 i�in mavi �izgi
//    cvLine(hist_img1,
//        cvPoint(bin_w * (i - 1), hist_h - height1),
//        cvPoint(bin_w * i, hist_h - height1),
//        cvScalar(255, 0, 0), 2, 8, 0);  // Mavi renk
//
//    // Histogram2 i�in ye�il �izgi
//    cvLine(hist_img2,
//        cvPoint(bin_w * (i - 1), hist_h - height2),
//        cvPoint(bin_w * i, hist_h - height2),
//        cvScalar(0, 255, 0), 2, 8, 0);  // Ye�il renk
//}
//
//// G�r�nt�leri ve histogramlar� g�ster
//cvNamedWindow("Gri G�r�nt� 1", CV_WINDOW_AUTOSIZE);
//cvShowImage("Gri G�r�nt� 1", gray1);
//
//cvNamedWindow("Gri G�r�nt� 2", CV_WINDOW_AUTOSIZE);
//cvShowImage("Gri G�r�nt� 2", gray2);
//
//// Histogramlar� g�ster
//cvNamedWindow("Histogram 1", CV_WINDOW_AUTOSIZE);
//cvShowImage("Histogram 1", hist_img1);
//
//cvNamedWindow("Histogram 2", CV_WINDOW_AUTOSIZE);
//cvShowImage("Histogram 2", hist_img2);
//
//// Bekle
//cvWaitKey(0);
//
//// Belle�i temizle
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
//// G�r�nt�y� y�kle
//IplImage* image = cvLoadImage("C:\\SS\\image2.jpg", 1);
//
//// Gri tonlamaya �evir
//IplImage* gray = cvCreateImage(cvGetSize(image), 8, 1);
//cvCvtColor(image, gray, CV_BGR2GRAY);
//
//// Histogram e�itleme
//IplImage* equalized = cvCreateImage(cvGetSize(image), 8, 1);
//cvEqualizeHist(gray, equalized);
//
//// Kenar tespiti (Canny)
//IplImage* edges = cvCreateImage(cvGetSize(image), 8, 1);
//cvCanny(equalized, edges, 50, 150, 3);
//
//// Sonu�lar� g�ster
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

//// G�r�nt�y� y�kle
//IplImage* image = cvLoadImage("C:\\SS\\image2.jpg", 1);
//
//// Gri tonlamaya �evir
//IplImage* gray = cvCreateImage(cvGetSize(image), 8, 1);
//cvCvtColor(image, gray, CV_BGR2GRAY);
//
//// Otsu ile e�ikleme
//IplImage* thresholded = cvCreateImage(cvGetSize(image), 8, 1);
//cvThreshold(gray, thresholded, 0, 255, CV_THRESH_BINARY + CV_THRESH_OTSU);
//
//// Kenar tespiti
//IplImage* edges = cvCreateImage(cvGetSize(image), 8, 1);
//cvCanny(thresholded, edges, 50, 150, 3);
//
//// Sonu�lar� g�ster
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

    /*// G�r�nt�leri y�kle
    IplImage* image = cvLoadImage("C:\\SS\\Image.jpg", CV_LOAD_IMAGE_COLOR);
    IplImage* template_img = cvLoadImage("C:\\SS\\image2.jpg", CV_LOAD_IMAGE_COLOR);

    // G�r�nt�leri gri tonlamaya d�n��t�r
    IplImage* gray_image = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
    IplImage* gray_template = cvCreateImage(cvGetSize(template_img), IPL_DEPTH_8U, 1);

    cvCvtColor(image, gray_image, CV_BGR2GRAY);
    cvCvtColor(template_img, gray_template, CV_BGR2GRAY);

    // Histogram hesaplama i�in gerekli parametreler
    int hist_size = 256;
    float range[] = { 0, 256 };
    float* hist_range[] = { range };

    // Template'in histogram�n� hesapla
    CvHistogram* hist = cvCreateHist(1, &hist_size, CV_HIST_ARRAY, hist_range, 1);
    cvCalcHist(&gray_template, hist, 0, NULL);

    // Histogramlar� normalize et
    cvNormalizeHist(hist, 1.0); // Histogram normalizasyonu

    // Back projection
    IplImage* back_project = cvCreateImage(cvGetSize(gray_image), IPL_DEPTH_8U, 1);
    cvCalcBackProject(&gray_image, back_project, hist);

    // Back projection'� g�rselle�tir
    cvNamedWindow("Back Projection", CV_WINDOW_AUTOSIZE);
    cvShowImage("Back Projection", back_project);
    cvWaitKey(0);

    // Belle�i temizle
    cvReleaseImage(&image);
    cvReleaseImage(&template_img);
    cvReleaseImage(&gray_image);
    cvReleaseImage(&gray_template);
    cvReleaseImage(&back_project);
    cvReleaseHist(&hist);

    cvDestroyAllWindows();*/

#pragma endregion

#pragma region Template Matching


    // G�r�nt�leri y�kle
    IplImage* image = cvLoadImage("C:\\SS\\indir.jpg", CV_LOAD_IMAGE_COLOR);
    IplImage* template_img = cvLoadImage("C:\\SS\\image2.jpg", CV_LOAD_IMAGE_COLOR);

    // G�r�nt�leri gri tonlamaya d�n��t�r
    IplImage* gray_image = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 1);
    IplImage* gray_template = cvCreateImage(cvGetSize(template_img), IPL_DEPTH_8U, 1);

    cvCvtColor(image, gray_image, CV_BGR2GRAY);
    cvCvtColor(template_img, gray_template, CV_BGR2GRAY);

    // Template matching i�lemi i�in uygun bir alan (MatchTemplate)
    IplImage* result = cvCreateImage(cvGetSize(gray_image), IPL_DEPTH_32F, 1);
    cvMatchTemplate(gray_image, gray_template, result, CV_TM_CCOEFF_NORMED);

    // Sonu�lar� g�rselle�tir
    double minVal, maxVal;
    CvPoint minLoc, maxLoc;
    cvMinMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, NULL);

    // En y�ksek benzerlik noktas�n� i�aretle
    cvRectangle(image, maxLoc, cvPoint(maxLoc.x + template_img->width, maxLoc.y + template_img->height), CV_RGB(0, 255, 0), 2);

    // Template matching sonras�n� g�rselle�tir
    cvNamedWindow("Template Matching", CV_WINDOW_AUTOSIZE);
    cvShowImage("Template Matching", image);
    cvWaitKey(0);

    // Belle�i temizle
    cvReleaseImage(&image);
    cvReleaseImage(&template_img);
    cvReleaseImage(&gray_image);
    cvReleaseImage(&gray_template);
    cvReleaseImage(&result);

    cvDestroyAllWindows();

     
#pragma endregion

    return 0;

}

