#include "overlay-layer.hpp"

#include <LayerShellQt/Window>

#include <QScreen>
#include <QString>
#include <QWidget>
#include <QWindow>
#include <Qt>

LayerShellQt::Window *configureOverlayLayer(QWidget &widget, QScreen *screen,
                                            bool takesKeyboard) {
  widget.setGeometry(screen->geometry());
  widget.winId();
  QWindow *window = widget.windowHandle();
  LayerShellQt::Window *layer =
      window ? LayerShellQt::Window::get(window) : nullptr;
  if (!layer)
    return nullptr;
  // Omarchy's layer rule matches this scope: no map animation, and kept out
  // of screen shares.
  layer->setScope(QStringLiteral("omasnap"));
  layer->setScreen(screen);
  layer->setLayer(LayerShellQt::Window::LayerOverlay);
  LayerShellQt::Window::Anchors anchors;
  anchors.setFlag(LayerShellQt::Window::AnchorTop);
  anchors.setFlag(LayerShellQt::Window::AnchorBottom);
  anchors.setFlag(LayerShellQt::Window::AnchorLeft);
  anchors.setFlag(LayerShellQt::Window::AnchorRight);
  layer->setAnchors(anchors);
  layer->setExclusiveZone(-1);
  layer->setKeyboardInteractivity(
      takesKeyboard ? LayerShellQt::Window::KeyboardInteractivityExclusive
                    : LayerShellQt::Window::KeyboardInteractivityNone);
  layer->setActivateOnShow(takesKeyboard);
  return layer;
}
