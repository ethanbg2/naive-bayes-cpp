#pragma once

#include <core/classifier.h>

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sketchpad.h"

namespace naivebayes {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class NaiveBayesApp : public ci::app::App {
 public:
  NaiveBayesApp();

  void draw() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  const double kWindowSize = 2000;
  const double kMargin = 300;
  const size_t kImageDimension = 28;

 private:
  Sketchpad sketchpad_;
  int current_prediction_ = -1;
  Classifier classifier;
};

}  // namespace visualizer

}  // namespace naivebayes
