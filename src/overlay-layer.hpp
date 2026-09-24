/** @fileoverview Full-output layer surfaces for the capture overlay. */
#pragma once

class QScreen;
class QWidget;
namespace LayerShellQt {
class Window;
}

/// Puts `widget` on a full-output layer surface on `screen`: Omasnap's
/// scope, the overlay layer, anchored to every edge and ignoring exclusive
/// zones, so a frozen frame painted into it lines up with the output. Only
/// the interactive overlay takes the keyboard. Null without a layer shell.
[[nodiscard]] LayerShellQt::Window *
configureOverlayLayer(QWidget &widget, QScreen *screen, bool takesKeyboard);
