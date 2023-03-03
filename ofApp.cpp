#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(20);

	for (int size = 30; size < 300; size += 30) {
		
		auto deg = ofMap(ofNoise(size * 0.0005 - ofGetFrameNum() * 0.0075), 0, 1, -720, 720);

		ofPushMatrix();
		ofRotateY(deg);

		size == 30 ? this->draw_arrow(glm::vec2(), glm::vec2(1, 0), size, ofColor(255, 0, 0), ofColor(0)) : this->draw_arrow(glm::vec2(), glm::vec2(1, 0), size, ofColor(0, 0), ofColor(0));

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
void ofApp::draw_arrow(glm::vec2 location, glm::vec2 target, float size, ofColor fill_color, ofColor no_fill_color) {

	auto angle = std::atan2(target.y - location.y, target.x - location.x);

	ofPushMatrix();
	ofTranslate(target);

	ofSetColor(fill_color);
	ofFill();
	ofBeginShape();
	ofVertex(glm::vec2(size * 0.8 * cos(angle), size * 0.8 * sin(angle)) + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) + location);
	ofEndShape(true);

	ofBeginShape();
	ofVertex(glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25 + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25 + location);
	ofEndShape(true);

	ofSetColor(no_fill_color);
	ofNoFill();
	ofBeginShape();
	ofVertex(glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25 + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) + location);
	ofVertex(glm::vec2(size * 0.8 * cos(angle), size * 0.8 * sin(angle)) + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25 + location);
	ofEndShape();

	ofBeginShape();
	ofVertex(glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25 + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5 + location);
	ofVertex(glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25 + location);
	ofEndShape();

	ofPopMatrix();
}
//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}