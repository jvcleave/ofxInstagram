#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    instagram.setup("6305138.976ac05.b29d71cfabee48d4a17883c7ce929fee","self");
    instagram.setCertFileLocation(ofToDataPath("ca-bundle.crt",false));
}
//--------------------------------------------------------------
void ofApp::update()
{

}
//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(0);
    instagram.drawJSON(10);
    if (!images.empty()) {
        for (int i = 0; i < images.size(); i++) {
            ofSetColor(255, 255, 255);
            if (images[i].isAllocated()) {
                images[i].draw();
            }
        }
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) {
        case 'f':
            images.clear();
            images.resize(12);
            instagram.getUserFeed(12);
            if (!instagram.getImageURL().empty())
            {
                for ( int i = 0; i < instagram.getImageURL().size(); i++)
                {
                    getImages.loadFromURL(images[i], instagram.getImageURL()[i]);
                    images[i].setImageID(instagram.getImageID()[i]);
                    if(i <= 3) {
                        images[i].setImageOrigin(5+(i*255), 5, 250,250);
                    }
                    else if(i >= 4 && i <= 7) {
                        images[i].setImageOrigin(5-(4*255)+(i*255), 5+255, 250,250);
                    }
                    else if(i >= 8 && i <= 11) {
                        images[i].setImageOrigin(5-(8*255)+(i*255), 5+2*255, 250,250);
                    }
                }
            }
            break;
        case 'S':
            instagram.saveJson("myFile");
            break;
        default:
            break;
    }
}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    
    if (!images.empty())
    {
        for(int i = 0; i < images.size(); i++)
        {
            images[i].isClicked(x, y);
        }
    }
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
    instagram.mouseScroll(scrollY);
}
