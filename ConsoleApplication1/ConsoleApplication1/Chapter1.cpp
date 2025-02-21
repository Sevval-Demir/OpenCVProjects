#include <opencv/cv.h>
#include <opencv/highgui.h>

int g_slider_position = 0;  // Trackbar'�n pozisyonu
CvCapture* g_capture = NULL;  // Video kayna��n� tutacak

// Trackbar kayd�r�ld���nda bu fonksiyon �al��acak
void onTrackbarSlide(int pos) {
    // Trackbar pozisyonuna g�re video karesine git
    cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

int main(int argc, char** argv) {
    // E�er dosya yolu verilmemi�se, hata mesaj� ver
    if (argc != 2) {
        std::cerr << "L�tfen bir video dosyas� yolu verin!" << std::endl;
        return -1;
    }

    // Pencereyi olu�tur
    cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);

    // Video dosyas�n� a�
    g_capture = cvCreateFileCapture("C:\\SS\\video.MOV");

    // Video kare say�s�n� al
    int frames = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);

    // E�er video kare say�s� 0'dan farkl� ise trackbar'� olu�tur
    if (frames != 0) {
        cvCreateTrackbar(
            "Position",         // Trackbar'�n ismi
            "Example3",         // Trackbar'�n bulundu�u pencere ismi
            &g_slider_position, // Trackbar'�n pozisyonu
            frames,             // Maksimum de�er (toplam kare say�s�)
            onTrackbarSlide     // Trackbar kayd�r�ld���nda �al��acak fonksiyon
        );
    }

    IplImage* frame;

    // Video oynatma d�ng�s�
    while (true) {
        // Trackbar'a g�re yeni bir kare al
        frame = cvQueryFrame(g_capture);

        // E�er kare al�namad�ysa, video bitti demek
        if (!frame) break;

        // Kareyi pencereye g�ster
        cvShowImage("Example3", frame);

        // Trackbar'� g�ncelle
        g_slider_position = (int)cvGetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES);

        // ESC tu�una bas�lana kadar videoyu g�stermeye devam et
        char c = cvWaitKey(33);
        if (c == 27) break;  // ESC tu�una bas�ld���nda ��k
    }

    // Video kayna��n� serbest b�rak
    cvReleaseCapture(&g_capture);

    // Pencereyi kapat
    cvDestroyWindow("Example3");

    return 0;
}
