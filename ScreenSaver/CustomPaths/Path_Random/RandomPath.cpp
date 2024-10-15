# ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_RANDOM_PATH
    # include "RandomPath.hpp"
    /**
     * @brief Construct a New RKRandomPath Object
     */
    RKRandomPath::RKRandomPath() {
        //-- Initialize Random Path
    }
    /**
     * @brief Destroy the RKRandomPath Object
     */
    RKRandomPath::~RKRandomPath() {
        //-- Destroy Random Path
    }
    # include <iostream>
    /**
     * @brief Get Random Path Position
     * @param time Time
     * @param scale Scale Factor to Make Curve Visible
     * @param centerX Center X
     * @param centerY Center Y
     * @return RKGPoint Position
     */
    RKGPoint RKRandomPath::getPosition(
        double time,
        double k,
        double scale,
        double centerX,
        double centerY
    ) {
        //-- Initialize Position
        RKGPoint position;
        //-- Calculate Position
        position.x = scale * (sin(time) + cos(((4 + k) + 3) * time)) + centerX;
        position.y = scale * (cos(time) - sin(((4 + k) - 1) * time)) + centerY;
        //-- Return Position
        return position;
    }
# endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_RANDOM_PATH