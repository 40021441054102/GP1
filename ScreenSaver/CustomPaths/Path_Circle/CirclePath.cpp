# ifndef RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH
    # include "CirclePath.hpp"
    /**
     * @brief Construct a New RKCirclePath Object
     */
    RKCirclePath::RKCirclePath() {}
    /**
     * @brief Destroy the RKCirclePath Object
     */
    RKCirclePath::~RKCirclePath() {}
    /**
     * @brief Method to Get Position of Circle Path According to Time
     * @param time Time
     * @param radius Radius
     * @param centerX Center X
     * @param centerY Center Y
     * @param centerZ Center Z
     * @note Default Values are Defined in Header File
     * @return RKGPoint Position
     */
    RKGPoint RKCirclePath::getPosition(
        double time,
        double radius,
        double centerX,
        double centerY,
        double centerZ
    ) {
        //-- Define Position
        RKGPoint position;
        //-- Set Position X
        position.x = centerX + radius * sin(time);
        //-- Set Position Y
        position.y = centerY + radius * sin(2 * time);
        //-- Set Position Z
        position.z = centerZ;
        //-- Return Position
        return position;
    }
# endif // RK_GRAPHICS_PROJECT_SCREEN_SAVER_CIRCLE_PATH