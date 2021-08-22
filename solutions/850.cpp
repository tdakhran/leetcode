#include <array>
#include <iostream>
#include <memory>
#include <vector>

struct Rectangle {
  bool contains(const Rectangle &o) const {
    return xb <= o.xb and yb <= o.yb and xu >= o.xu and yu >= o.yu;
  }

  bool intersects(const Rectangle &o) const {
    if (xb >= o.xu or o.xb >= xu) {
      return false;
    }
    if (yb >= o.yu or o.yb >= yu) {
      return false;
    }
    return true;
  }

  bool valid() const { return xb < xu and yb < yu; }

  int64_t area() const { return static_cast<int64_t>(yu - yb) * (xu - xb); }

 public:
  int xb, yb, xu, yu;
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
struct NonaTreeCanvas {
  explicit NonaTreeCanvas(Rectangle &&rectangle)
      : canvas_rectangle(std::move(rectangle)) {}

  int64_t filled_area() const {
    if (fully_filled) {
      return canvas_rectangle.area();
    }
    if (clean) {
      return 0;
    }

    int64_t filled_children_area = 0;
    for (auto &child_canvas_row : children) {
      for (auto &child_canvas : child_canvas_row) {
        if (child_canvas) {
          filled_children_area += child_canvas->filled_area();
        }
      }
    }
    return filled_children_area;
  }

  void draw(const Rectangle &rectangle) {
    if (fully_filled) {
      return;
    }

    if (rectangle.contains(canvas_rectangle)) {
      fully_filled = true;
      return;
    }

    auto model = this;
    if (not canvas_rectangle.intersects(rectangle)) {
      return;
    }

    if (clean) {
      clean = false;
      std::array<int, 4> x_points{canvas_rectangle.xb, rectangle.xb,
                                  rectangle.xu, canvas_rectangle.xu};
      std::array<int, 4> y_points{canvas_rectangle.yb, rectangle.yb,
                                  rectangle.yu, canvas_rectangle.yu};

      for (size_t y = 0; y < 3; ++y) {
        for (size_t x = 0; x < 3; ++x) {
          Rectangle potential_child_canvas{
              std::max(x_points[x], model->canvas_rectangle.xb),
              std::max(y_points[y], model->canvas_rectangle.yb),
              std::min(x_points[x + 1], model->canvas_rectangle.xu),
              std::min(y_points[y + 1], model->canvas_rectangle.yu)};
          if (potential_child_canvas.valid()) {
            model->children[y][x] = std::make_unique<NonaTreeCanvas>(
                std::move(potential_child_canvas));
          }
        }
      }
    }

    for (auto &child_canvas_row : model->children) {
      for (auto &child_canvas : child_canvas_row) {
        if (child_canvas) {
          child_canvas->draw(rectangle);
        }
      }
    }
  }

 public:
  Rectangle canvas_rectangle;
  std::array<std::array<std::unique_ptr<NonaTreeCanvas>, 3>, 3> children{
      {{nullptr}}};
  bool fully_filled = false;
  bool clean = true;
};
#pragma clang diagnostic pop

class Solution {
 public:
  int rectangleArea(std::vector<std::vector<int>> &rectangles) {
    auto side = (1 << 30);  // huge canvas to fit all rectangles

    auto canvas = std::make_unique<NonaTreeCanvas>(Rectangle{0, 0, side, side});
    for (const auto &r : rectangles) {
      canvas->draw(Rectangle{r[0], r[1], r[2], r[3]});
    }
    return canvas->filled_area() % 1'000'000'007;
  }
};
