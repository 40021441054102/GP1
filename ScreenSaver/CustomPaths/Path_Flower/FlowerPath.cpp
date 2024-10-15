# ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_FLOWER_PATH
    # include "FlowerPath.hpp"
    /**
     * @brief Construct a New RKFlowerPath Object
     */
    RKFlowerPath::RKFlowerPath() {
        //-- Initialize Flower Path
    }
    /**
     * @brief Destroy the RKFlowerPath Object
     */
    RKFlowerPath::~RKFlowerPath() {
        //-- Destroy Flower Path
    }
    /**
     * @brief Get Flower Path Position
     * @param time Time
     * @param k Number of Petals
     * @param scale Scale Factor to Make Curve Visible
     * @param centerX Center X
     * @param centerY Center Y
     * @return RKGPoint Position
     */
    RKGPoint RKFlowerPath::getPosition(
        double time,
        int k,
        double scale,
        double centerX,
        double centerY
    ) {
        // //-- Initialize Position
        // RKGPoint position;
        // //-- Calculate Position
        // position.x = scale * (cos(time) + cos((k - 1) * time)) + centerX;
        // position.y = scale * (sin(time) - sin((k - 1) * time)) + centerY;
        // //-- Return Position
        // return position;
        //-- Initialize Position
        RKGPoint position;
        //-- Calculate Position
        position.x = scale * (sin(time) + cos((k + 3) * time)) + centerX;
        position.y = scale * (cos(time) - sin((k - 1) * time)) + centerY;
        //-- Return Position
        return position;
    }
        // //-- Initialize Position
        // RKGPoint position;
        // //-- Calculate Position
        // position.x = scale * (cos(time) + cos((k + 3) * time)) + centerX;
        // position.y = scale * (sin(time) - sin((k - 1) * time)) + centerY;
        // //-- Return Position
        // return position;

        // //-- Initialize Position
        // RKGPoint position;
        // //-- Calculate Position
        // position.x = scale * (cos(time) + cos((k + 1) * time)) + centerX;
        // position.y = scale * (sin(time) - sin((k - 1) * time)) + centerY;
        // //-- Return Position
        // return position;

        // //-- Initialize Position
        // RKGPoint position;
        // //-- Calculate Position
        // position.x = scale * (cos(time) + cos((k + 1) * time)) + centerX;
        // position.y = scale * (cos(time) - sin((k - 1) * time)) + centerY;
        // //-- Return Position
        // return position;

        // //-- Initialize Position
        // RKGPoint position;
        // //-- Calculate Position
        // position.x = scale * (sin(time) + cos((k - 1) * time)) + centerX;
        // position.y = scale * (sin(time) - sin((k - 1) * time)) + centerY;
        // //-- Return Position
        // return position;

        // // -- Initialize Position
        // RKGPoint position;
        // // -- Calculate Position
        // position.x = scale * (cos(time) + cos((k - 1) * time)) + centerX;
        // position.y = scale * (cos(time) - sin((k - 1) * time)) + centerY;
        // // -- Return Position
        // return position;

        // //-- Initialize Position
        // RKGPoint position;
        // //-- Calculate Position
        // position.x = scale * (sin(time) + cos((k - 1) * time)) + centerX;
        // position.y = scale * (cos(time) - sin((k - 1) * time)) + centerY;
        // //-- Return Position
        // return position;
# endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_FLOWER_PATH