#include <opencv/cv.h>
#include <opencv/highgui.h>

int g_slider_position = 0;  // Trackbar'ýn pozisyonu
CvCapture* g_capture = NULL;  // Video kaynaðýný tutacak

// Trackbar kaydýrýldýðýnda bu fonksiyon çalýþacak
void onTrackbarSlide(int pos) {
    // Trackbar pozisyonuna göre video karesine git
    cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

int main(int argc, char** argv) {
    // Eðer dosya yolu verilmemiþse, hata mesajý ver
    if (argc != 2) {
        std::cerr << "Lütfen bir video dosyasý yolu verin!" << std::endl;
        return -1;
    }

    // Pencereyi oluþtur
    cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);

    // Video dosyasýný aç
    g_capture = cvCreateFileCapture("C:\\SS\\video.MOV");

    // Video kare sayýsýný al
    int frames = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);

    // Eðer video kare sayýsý 0'dan farklý ise trackbar'ý oluþtur
    if (frames != 0) {
        cvCreateTrackbar(
            "Position",         // Trackbar'ýn ismi
            "Example3",         // Trackbar'ýn bulunduðu pencere ismi
            &g_slider_position, // Trackbar'ýn pozisyonu
            frames,             // Maksimum deðer (toplam kare sayýsý)
            onTrackbarSlide     // Trackbar kaydýrýldýðýnda çalýþacak fonksiyon
        );
    }

    IplImage* frame;

    // Video oynatma döngüsü
    while (true) {
        // Trackbar'a göre yeni bir kare al
        frame = cvQueryFrame(g_capture);

        // Eðer kare alýnamadýysa, video bitti demek
        if (!frame) break;

        // Kareyi pencereye göster
        cvShowImage("Example3", frame);

        // Trackbar'ý güncelle
        g_slider_position = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES);

        // ESC tuþuna basýlana kadar videoyu göstermeye devam et
        char c = cvWaitKey(33);
        if (c == 27) break;  // ESC tuþuna basýldýðýnda çýk
    }

    // Video kaynaðýný serbest býrak
    cvReleaseCapture(&g_capture);

    // Pencereyi kapat
    cvDestroyWindow("Example3");

    return 0;
}
