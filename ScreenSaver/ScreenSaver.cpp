# ifndef RK_GRAPHICS_PROJECT_1
    # include "ScreenSaver.hpp"
    /**
     * @brief Method to Construct a New RKScreenSaver Object
     */
    RKScreenSaver::RKScreenSaver() {
        //-- Show Log Message
        logger(RKG_LABEL INFO "Starting Screen Saver ...");
        //-- Set OpenGL Ortho
        glOrtho(
            0.0,RK_SCREEN_SAVER_WINDOW_WIDTH,
            0.0, RK_SCREEN_SAVER_WINDOW_HEIGHT,
            -1.0, 1.0
        );
        //-- Obtain a Random Number from Hardware
        std::random_device rd;
        //-- Seed the Generator
        std::mt19937 gen(rd());
        //-- Define Distribution for Color
        std::uniform_int_distribution<> dis_color(73, 255);
        //-- Define Distribution for Point Position Noises
        std::uniform_int_distribution<> dis_noise(100, 300);
        //-- Define Distribution for Sign
        std::uniform_int_distribution<> dis_sign(0, 1);
        //-- Define Point 1 X
        int x1 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2 - 200;
        //-- Define Point 1 Y
        int y1 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
        //-- Define Point 2 X
        int x2 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2 + 200;
        //-- Define Point 2 Y
        int y2 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
        //-- Define Noises
        int noise_1 = 0, noise_2 = 0, noise_3 = 0, noise_4 = 0;
        //-- Define Sign
        int sign = 1;
        //-- Window Loop
        while (true) {
            //-- Clear the Window
            window.clear(0, 10, 18, 255);
            //-- Draw a Line
            line.drawLine(
                x1, y1,
                x2, y2,
                0.0f, 0.0f,
                {
                    0,
                    dis_color(gen),
                    dis_color(gen)
                }
            );
            //-- Draw a Line
            line.drawLine(
                x1, y2,
                x2, y1,
                0.0f, 0.0f,
                {
                    0,
                    dis_color(gen),
                    dis_color(gen)
                }
            );
            //-- Set Noise 1
            noise_1 = dis_noise(gen) * dis_sign(gen) == 0 ? -1 : 1;
            //-- Set Noise 2
            noise_2 = dis_noise(gen) * dis_sign(gen) == 0 ? -1 : 1;
            //-- Set Noise 3
            noise_3 = dis_noise(gen) * dis_sign(gen) == 0 ? -1 : 1;
            //-- Set Noise 4
            noise_4 = dis_noise(gen) * dis_sign(gen) == 0 ? -1 : 1;
            //-- Add Noise to Points and Check they are in the Window
            if (x1 + noise_1 > 0 && x1 + noise_1 < RK_SCREEN_SAVER_WINDOW_WIDTH) {
                x1 += noise_1;
            }
            if (y1 + noise_2 > 0 && y1 + noise_2 < RK_SCREEN_SAVER_WINDOW_HEIGHT) {
                y1 += noise_2;
            }
            if (x2 + noise_3 > 0 && x2 + noise_3 < RK_SCREEN_SAVER_WINDOW_WIDTH) {
                x2 += noise_3;
            }
            if (y2 + noise_4 > 0 && y2 + noise_4 < RK_SCREEN_SAVER_WINDOW_HEIGHT) {
                y2 += noise_4;
            }
            //-- Update the Window
            window.update();
        }
    }
    /**
     * @brief Method to Construct a New RKScreenSaver Object
     * @param type Screen Saver Type
     */
    RKScreenSaver::RKScreenSaver(int type = RK_SCREEN_SAVER_CIRCLE) {
        //-- Show Log Message
        logger(RKG_LABEL INFO "Starting Screen Saver ...");
        //-- Set OpenGL Ortho
        glOrtho(
            0.0,RK_SCREEN_SAVER_WINDOW_WIDTH,
            0.0, RK_SCREEN_SAVER_WINDOW_HEIGHT,
            -1.0, 1.0
        );
        //-- Handle Screen Saver Type
        switch (type) {
            //-- Test Screen Saver
            case RK_SCREEN_SAVER_TEST: {
                RKPolygon polygon;
                std::deque<RKGPointColor> polyBuffer;
                RKGPointColor p1,p2,p3,p4;
                p1.x = RK_SCREEN_SAVER_WINDOW_WIDTH * 1 / 3;
                p1.y = RK_SCREEN_SAVER_WINDOW_HEIGHT * 1 / 3;
                p2.x = RK_SCREEN_SAVER_WINDOW_WIDTH * 1 / 3;
                p2.y = RK_SCREEN_SAVER_WINDOW_HEIGHT * 2 / 3;
                p3.x = RK_SCREEN_SAVER_WINDOW_WIDTH * 2 / 3;
                p3.y = RK_SCREEN_SAVER_WINDOW_HEIGHT * 2 / 3;
                p4.x = RK_SCREEN_SAVER_WINDOW_WIDTH * 2 / 3;
                p4.y = RK_SCREEN_SAVER_WINDOW_HEIGHT * 1 / 3;
                polyBuffer.push_back(p1);
                polyBuffer.push_back(p2);
                polyBuffer.push_back(p3);
                polyBuffer.push_back(p4);
                while (true) {
                    //-- Clear the Window
                    window.clear(0, 10, 18, 255);
                    //-- Draw Polygon
                    polygon.drawPolygon(
                        polyBuffer
                    );
                    //-- Update the Window
                    window.update();
                    //-- Sleep
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
                break;
            }
            //-- Circle Screen Saver
            case RK_SCREEN_SAVER_CIRCLE: {
                //-- Create Circle Path Object
                RKCirclePath circle_path;
                //-- Define Time
                double time = 0.0;
                //-- Obtain a Random Number from Hardware
                std::random_device rd;
                //-- Seed the Generator
                std::mt19937 gen(rd());
                //-- Define Distribution for Color
                std::uniform_int_distribution<> dis_color(73, 255);
                //-- Define Distribution for Point Position Noises
                std::uniform_int_distribution<> dis_noise(5, 10);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign(0, 1);
                //-- Define Point 1 X
                int x1 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2 - 200;
                //-- Define Point 1 Y
                int y1 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Point 2 X
                int x2 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2 + 200;
                //-- Define Point 2 Y
                int y2 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Noises
                int noise_1 = 0, noise_2 = 0, noise_3 = 0, noise_4 = 0;
                //-- Define Sign
                int sign1, sign2, sign3, sign4;
                //-- Window Loop
                while (true) {
                    //-- Clear the Window
                    // window.clear(0, 10, 18, 255);
                    //-- Get Position
                    RKGPoint position = circle_path.getPosition(time);
                    //-- Set Sign 1
                    sign1 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set Sign 2
                    sign2 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set Sign 3
                    sign3 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set Sign 4
                    sign4 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set x1
                    x1 = position.x + dis_noise(gen) * sign1; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set y1
                    y1 = position.y + dis_noise(gen) * sign2; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set x2
                    x2 = position.x + dis_noise(gen) * sign3; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set y2
                    y2 = position.y + dis_noise(gen) * sign4; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Draw a Line
                    line.drawLine(
                        x1, y1,
                        x2, y2,
                        0.0f, 0.0f,
                        {
                            0,
                            dis_color(gen),
                            dis_color(gen)
                        }
                    );
                    //-- Update the Window
                    window.update();
                    //-- Update Time
                    time += 0.01;
                    //-- Sleep
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
                break;
            }
            //-- Infinity Screen Saver
            case RK_SCREEN_SAVER_INFINITE: {
                //-- Create Infinity Path Object
                RKInfinityPath infinity_path;
                //-- Define Time
                double time = 0.0;
                //-- Obtain a Random Number from Hardware
                std::random_device rd;
                //-- Seed the Generator
                std::mt19937 gen(rd());
                //-- Define Distribution for Color
                std::uniform_int_distribution<> dis_color(73, 255);
                //-- Define Distribution for Point Position Noises
                std::uniform_int_distribution<> dis_noise(5, 10);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign(0, 1);
                //-- Define Point 1 X
                int x1 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2 - 200;
                //-- Define Point 1 Y
                int y1 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Point 2 X
                int x2 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2 + 200;
                //-- Define Point 2 Y
                int y2 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Noises
                int noise_1 = 0, noise_2 = 0, noise_3 = 0, noise_4 = 0;
                //-- Define Sign
                int sign1, sign2, sign3, sign4;
                //-- Window Loop
                while (true) {
                    //-- Clear the Window
                    // window.clear(0, 10, 18, 255);
                    //-- Get Position
                    RKGPoint position = infinity_path.getPosition(time);
                    //-- Set Sign 1
                    sign1 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set Sign 2
                    sign2 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set Sign 3
                    sign3 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set Sign 4
                    sign4 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set x1
                    x1 = position.x + dis_noise(gen) * sign1; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set y1
                    y1 = position.y + dis_noise(gen) * sign2; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set x2
                    x2 = position.x + dis_noise(gen) * sign3; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set y2
                    y2 = position.y + dis_noise(gen) * sign4; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Draw a Line
                    line.drawLine(
                        x1, y1,
                        x2, y2,
                        0.0f, 0.0f,
                        {
                            0,
                            dis_color(gen),
                            dis_color(gen)
                        }
                    );
                    //-- Update the Window
                    window.update();
                    //-- Update Time
                    time += 0.01;
                    //-- Sleep
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
                break;
            }
            //-- Flower Screen Saver
            case RK_SCREEN_SAVER_WISH_FLOWER: {
                //-- Create Flower Path Object
                RKFlowerPath flower_path;
                //-- Define Time
                double time = 0.0;
                //-- Obtain a Random Number from Hardware
                std::random_device rd;
                //-- Seed the Generator
                std::mt19937 gen(rd());
                //-- Define Distribution for Color
                std::uniform_int_distribution<> dis_color(73, 255);
                //-- Define Distribution for Point Position Noises
                std::uniform_int_distribution<> dis_noise(5, 10);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign(0, 1);
                //-- Define Point 1 X
                int x1 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2 - 200;
                //-- Define Point 1 Y
                int y1 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Point 2 X
                int x2 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2 + 200;
                //-- Define Point 2 Y
                int y2 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Noises
                int noise_1 = 0, noise_2 = 0, noise_3 = 0, noise_4 = 0;
                //-- Define Sign
                int sign1, sign2, sign3, sign4;
                //-- Window Loop
                while (true) {
                    //-- Clear the Window
                    // window.clear(0, 10, 18, 255);
                    //-- Get Position
                    RKGPoint position = flower_path.getPosition(time);
                    //-- Set Sign 1
                    sign1 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set Sign 2
                    sign2 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set Sign 3
                    sign3 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set Sign 4
                    sign4 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set x1
                    x1 = position.x + dis_noise(gen) * sign1; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set y1
                    y1 = position.y + dis_noise(gen) * sign2; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set x2
                    x2 = position.x + dis_noise(gen) * sign3; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set y2
                    y2 = position.y + dis_noise(gen) * sign4; // * dis_sign(gen) == 0 ? -1 : 1;
                    //-- Draw a Line
                    line.drawLine(
                        x1, y1,
                        x2, y2,
                        0.0f, 0.0f,
                        {
                            0,
                            dis_color(gen),
                            dis_color(gen)
                        }
                    );
                    //-- Update the Window
                    window.update();
                    //-- Update Time
                    time += 0.01;
                    //-- Sleep
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
                break;
            }
            //-- Custom Screen Saver
            case RK_SCREEN_SAVER_CUSTOM: {
                //-- Define Line Structure
                struct Line {
                    float x1, y1, x2, y2;
                    float r, g, b;
                };
                //-- Define a Buffer to Store the Last N Lines
                std::deque<Line> linesBuffer;
                //-- Define the Maximum Number of Lines
                const size_t maxLines = 100;
                //-- Create Random Path Object
                RKRandomPath random_path;
                // RKInfinityPath random_path;
                //-- Define Time
                double time = 0.0;
                //-- Obtain a Random Number from Hardware
                std::random_device rd;
                //-- Seed the Generator
                std::mt19937 gen(rd());
                //-- Define Distribution for Color
                std::uniform_int_distribution<> dis_color(73, 255);
                //-- Define Distribution for Point Position Noises
                std::uniform_int_distribution<> dis_noise(5, 15);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign(0, 1);
                //-- Define Distribution for K
                std::uniform_real_distribution<> dis_k(0, 2);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign_k(-1, 1);
                //-- Define Point 1 X
                int x1 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2;
                //-- Define Point 1 Y
                int y1 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Point 2 X
                int x2 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2;
                //-- Define Point 2 Y
                int y2 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Noises
                int noise_1 = 0, noise_2 = 0, noise_3 = 0, noise_4 = 0;
                //-- Define Sign
                int sign1, sign2, sign3, sign4;
                //-- Define RKLine Object
                RKLine lineDrawer;
                //-- Window Loop
                while (true) {
                    //-- Clear the Window
                    window.clear(0, 10, 18, 255);
                    //-- Get Position
                    RKGPoint position = random_path.getPosition(time);
                    //-- Set Signs
                    sign1 = dis_sign(gen) == 0 ? -1 : 1;
                    sign2 = dis_sign(gen) == 0 ? -1 : 1;
                    sign3 = dis_sign(gen) == 0 ? -1 : 1;
                    sign4 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set x1 and y1
                    // x1 = position.x + dis_noise(gen) * sign1;
                    // y1 = position.y + dis_noise(gen) * sign2;
                    // //-- Set x2 and y2
                    x2 = position.x + dis_noise(gen) * sign3;
                    y2 = position.y + dis_noise(gen) * sign4;
                    // x1 = 0;
                    // y1 = 0;


                    //-- Smooth Color Changes
                    // float green = (sin(time * 2) * 0.5f + 0.5f) * 255;
                    // float blue = (cos(time * 2) * 0.5f + 0.5f) * 255;
                    float red   = (sin(2 * time + 0) * 0.5f + 0.5f) * 255;
                    float green = (sin(2 * time + 2.0f) * 0.5f + 0.5f) * 255;
                    float blue  = (sin(2 * time + 4.0f) * 0.5f + 0.5f) * 255;
                    //-- Add the New Line to the Buffer
                    linesBuffer.push_back({
                        static_cast<float>(x1),
                        static_cast<float>(y1),
                        static_cast<float>(x2),
                        static_cast<float>(y2),
                        float(red),
                        float(green),
                        float(blue)
                    });
                    //-- Remove the Oldest Line
                    if (linesBuffer.size() > maxLines) {
                        linesBuffer.pop_front();
                    }
                    //-- Draw All Lines in the Buffer
                    for (const auto& line : linesBuffer) {
                        lineDrawer.drawLine(
                            static_cast<int>(line.x1), static_cast<int>(line.y1),
                            static_cast<int>(line.x2), static_cast<int>(line.y2),
                            0.0f, 0.0f, 
                            {
                                static_cast<int>(line.r),
                                static_cast<int>(line.g),
                                static_cast<int>(line.b),
                                255
                            }
                        );
                    }
                    //-- Update the Window
                    window.update();
                    //-- Update Time
                    time += 0.02;
                    //-- Sleep
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
                break;
            }
            //-- Custom Polygon Screen Saver
            case RK_SCREEN_SAVER_CUSTOM_POLYGON: {
                //-- Define a Buffer to Store the Last N Polygons
                std::deque<RKGPointColor> polyBuffer;
                //-- Define the Maximum Number of Polygons
                const size_t maxPolys = 200;
                //-- Create Random Path Object
                // RKRandomPath random_path;
                RKRandomPath random_path;
                //-- Define Time
                double time = 0.0;
                //-- Obtain a Random Number from Hardware
                std::random_device rd;
                //-- Seed the Generator
                std::mt19937 gen(rd());
                //-- Define Distribution for Color
                std::uniform_int_distribution<> dis_color(73, 255);
                //-- Define Distribution for Point Position Noises
                std::uniform_int_distribution<> dis_noise(1, 3);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign(0, 1);
                //-- Define Distribution for K
                std::uniform_real_distribution<> dis_k(0, 2);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign_k(-1, 1);
                //-- Define Point 1 X
                int x1 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2;
                //-- Define Point 1 Y
                int y1 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Sign
                int sign1, sign2;
                //-- Define RKPolygon Object
                RKPolygon polygon;
                //-- Window Loop
                while (true) {
                    //-- Clear the Window
                    window.clear(0, 10, 18, 255);
                    //-- Get Position
                    RKGPoint position = random_path.getPosition(time);
                    //-- Set Signs
                    sign1 = dis_sign(gen) == 0 ? -1 : 1;
                    sign2 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Smooth Color Changes
                    // float green = (sin(time * 2) * 0.5f + 0.5f) * 255;
                    // float blue = (cos(time * 2) * 0.5f + 0.5f) * 255;
                    float red   = (sin(2 * time + 0) * 0.5f + 0.5f) * 255;
                    // red = 0.0;
                    float green = (cos(2 * time + 3.0f) * 0.5f + 0.5f) * 255;
                    float blue  = (sin(2 * time + 4.0f) * 0.5f + 0.5f) * 255;
                    //-- Define Color Object
                    RKGColor color;
                    //-- Set Colors
                    color.r = red;
                    color.g = green;
                    color.b = blue;
                    //-- Define RKGPointColor Object
                    RKGPointColor point;
                    //-- Set Point Propetries
                    point.x = position.x; // + dis_noise(gen) * sign1;
                    point.y = position.y; // + dis_noise(gen) * sign2;
                    point.z = 0;
                    point.color = color;
                    //-- Add the New Line to the Buffer
                    polyBuffer.push_back(point);
                    //-- Remove the Oldest Line
                    if (polyBuffer.size() > maxPolys) {
                        polyBuffer.pop_front();
                    }
                    //-- Draw All Lines in the Buffer
                    for (const auto& line : polyBuffer) {
                        polygon.drawPolygon(polyBuffer);
                    }
                    //-- Update the Window
                    window.update();
                    // std::cout << time << std::endl;
                    //-- Update Time
                    time += 0.01;
                    //-- Sleep
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
                break;
            }
            //-- Custom Line Polygon Screen Saver
            case RK_SCREEN_SAVER_CUSTOM_POLYGON_LINE: {
                //-- Define a Buffer to Store the Last N Polygons
                std::deque<RKGPointColor> polyBuffer;
                //-- Define the Maximum Number of Polygons
                const size_t maxPolys = 210;
                //-- Create Random Path Object
                // RKRandomPath random_path;
                RKFlowerPath random_path;
                //-- Define Time
                double time = 0.6;
                //-- Obtain a Random Number from Hardware
                std::random_device rd;
                //-- Seed the Generator
                std::mt19937 gen(rd());
                //-- Define Distribution for Color
                std::uniform_int_distribution<> dis_color(73, 255);
                //-- Define Distribution for Point Position Noises
                std::uniform_int_distribution<> dis_noise(5, 15);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign(0, 1);
                //-- Define Distribution for K
                std::uniform_real_distribution<> dis_k(0, 2);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign_k(-1, 1);
                //-- Define Point 1 X
                int x1 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2;
                //-- Define Point 1 Y
                int y1 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Sign
                int sign1, sign2;
                //-- Define RKPolygon Object
                RKPolygon polygon;
                //-- Window Loop
                while (true) {
                    //-- Clear the Window
                    window.clear(0, 10, 18, 255);
                    //-- Get Position
                    RKGPoint position = random_path.getPosition(time);
                    //-- Set Signs
                    sign1 = dis_sign(gen) == 0 ? -1 : 1;
                    sign2 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Smooth Color Changes
                    // float green = (sin(time * 2) * 0.5f + 0.5f) * 255;
                    // float blue = (cos(time * 2) * 0.5f + 0.5f) * 255;
                    float red   = (sin(2 * time + 0) * 0.5f + 0.5f) * 255;
                    float green = (sin(2 * time + 2.0f) * 0.5f + 0.5f) * 255;
                    float blue  = (sin(2 * time + 4.0f) * 0.5f + 0.5f) * 255;
                    //-- Define Color Object
                    RKGColor color;
                    //-- Set Colors
                    color.r = red;
                    color.g = green;
                    color.b = blue;
                    //-- Define RKGPointColor Object
                    RKGPointColor point;
                    //-- Set Point Propetries
                    point.x = position.x + dis_noise(gen) * sign1;
                    point.y = position.y + dis_noise(gen) * sign2;
                    point.z = 0;
                    point.color = color;
                    //-- Add the New Line to the Buffer
                    polyBuffer.push_back(point);
                    //-- Remove the Oldest Line
                    if (polyBuffer.size() > maxPolys) {
                        polyBuffer.pop_front();
                    }
                    //-- Draw All Lines in the Buffer
                    for (const auto& line : polyBuffer) {
                        polygon.drawLinePolygon(polyBuffer);
                    }
                    //-- Update the Window
                    window.update();
                    // std::cout << time << std::endl;
                    //-- Update Time
                    time += 0.03;
                    //-- Sleep
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
                break;
            }
            //-- Random Screen Saver
            case RK_SCREEN_SAVER_RANDOM: {
                //-- Define Line Structure
                struct Line {
                    float x1, y1, x2, y2;
                    float r, g, b;
                };
                //-- Define a Buffer to Store the Last N Lines
                std::deque<Line> linesBuffer;
                //-- Define the Maximum Number of Lines
                const size_t maxLines = 80;
                //-- Create Random Path Object
                RKRandomPath random_path;
                // RKInfinityPath random_path;
                //-- Define Time
                double time = 0.0;
                //-- Obtain a Random Number from Hardware
                std::random_device rd;
                //-- Seed the Generator
                std::mt19937 gen(rd());
                //-- Define Distribution for Color
                std::uniform_int_distribution<> dis_color(73, 255);
                //-- Define Distribution for Point Position Noises
                std::uniform_int_distribution<> dis_noise(5, 15);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign(0, 1);
                //-- Define Distribution for K
                std::uniform_real_distribution<> dis_k(0, 2);
                //-- Define Distribution for Sign
                std::uniform_int_distribution<> dis_sign_k(-1, 1);
                //-- Define Point 1 X
                int x1 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2;
                //-- Define Point 1 Y
                int y1 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Point 2 X
                int x2 = RK_SCREEN_SAVER_WINDOW_WIDTH / 2;
                //-- Define Point 2 Y
                int y2 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2;
                //-- Define Noises
                int noise_1 = 0, noise_2 = 0, noise_3 = 0, noise_4 = 0;
                //-- Define Sign
                int sign1, sign2, sign3, sign4;
                //-- Define RKLine Object
                RKLine lineDrawer;
                //-- Window Loop
                while (true) {
                    //-- Clear the Window
                    window.clear(0, 10, 18, 255);
                    //-- Get Position
                    RKGPoint position = random_path.getPosition(time);
                    //-- Set Signs
                    sign1 = dis_sign(gen) == 0 ? -1 : 1;
                    sign2 = dis_sign(gen) == 0 ? -1 : 1;
                    sign3 = dis_sign(gen) == 0 ? -1 : 1;
                    sign4 = dis_sign(gen) == 0 ? -1 : 1;
                    //-- Set x1 and y1
                    x1 = position.x + dis_noise(gen) * sign1;
                    y1 = position.y + dis_noise(gen) * sign2;
                    // //-- Set x2 and y2
                    x2 = position.x + dis_noise(gen) * sign3;
                    y2 = position.y + dis_noise(gen) * sign4;
                    // y1 = RK_SCREEN_SAVER_WINDOW_HEIGHT / 2 + position.y;
                    // x1 = 0;
                    // y1 = 0;


                    //-- Smooth Color Changes
                    // float green = (sin(time * 2) * 0.5f + 0.5f) * 255;
                    // float blue = (cos(time * 2) * 0.5f + 0.5f) * 255;
                    float red   = (sin(2 * time + 0) * 0.5f + 0.5f) * 255;
                    float green = (sin(2 * time + 2.0f) * 0.5f + 0.5f) * 255;
                    float blue  = (sin(2 * time + 4.0f) * 0.5f + 0.5f) * 255;
                    //-- Add the New Line to the Buffer
                    linesBuffer.push_back({
                        static_cast<float>(x1),
                        static_cast<float>(y1),
                        static_cast<float>(x2),
                        static_cast<float>(y2),
                        float(red),
                        float(green),
                        float(blue)
                    });
                    //-- Remove the Oldest Line
                    if (linesBuffer.size() > maxLines) {
                        linesBuffer.pop_front();
                    }
                    //-- Draw All Lines in the Buffer
                    for (const auto& line : linesBuffer) {
                        lineDrawer.drawLine(
                            static_cast<int>(line.x1), static_cast<int>(line.y1),
                            static_cast<int>(line.x2), static_cast<int>(line.y2),
                            0.0f, 0.0f, 
                            {
                                static_cast<int>(line.r),
                                static_cast<int>(line.g),
                                static_cast<int>(line.b),
                                255
                            }
                        );
                    }
                    //-- Update the Window
                    window.update();
                    //-- Update Time
                    time += 0.002;
                    //-- Sleep
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                }
                break;
            }
        };
    }
# endif // RK_GRAPHICS_PROJECT_1


// void drawScreenSaver() {  
//         glClear(GL_COLOR_BUFFER_BIT);
//         glColor3f(1.0, 1.0, 1.0);
//         // Draw a polygon with specified vertices.
        
//         glPointSize(5.0); // Set point size.
        
//         //-- Obtain a Random Number from Hardware
//         std::random_device rd;
//         //-- Seed the Generator
//         std::mt19937 gen(rd());
//         //-- Define Distribution for X
//         std::uniform_int_distribution<> dis_p1(1, 100);
//         //-- Define Distribution for Y
//         std::uniform_int_distribution<> dis_p2(1, 100);
//         //-- Define Distribution for Y
//         std::uniform_int_distribution<> dis_color(15, 255);

//         std::cout << dis_p1(gen) << " - " << dis_p2(gen) << std::endl;
//         glBegin(GL_LINES);
//         // glBegin(GL_LINE_STRIP);
//             // glVertex3f(20.0, 20.0, 0.0);
//             // glVertex3f(80.0, 20.0, 0.0);
//             while (true) {
//                 glColor3f(
//                     0,
//                     COLOR2FLOAT(dis_color(gen)),
//                     COLOR2FLOAT(dis_color(gen))
//                 );
//                 glBegin(GL_LINE_LOOP);
//                 glVertex3f(float(dis_p1(gen)), float(dis_p2(gen)), 0.0);
//                 glVertex3f(float(dis_p1(gen)), float(dis_p2(gen)), 0.0);
//                 glEnd();

//                 glFlush(); 

//             }
//     }
//     // OpenGL window reshape routine.
//     void resize(int w, int h) {
//         glViewport(0, 0, w, h);
//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//     }
//     // Keyboard input processing routine.
//     void keyInput(unsigned char key, int x, int y) {
//     switch(key) {
//         case 27:
//             exit(0);
//             break;
//         default:
//             break;
//         }
//     }
//     /**
//      * @brief Method to Construct a New RKScreenSaver Object
//      */
//     RKScreenSaver::RKScreenSaver() {
//         counter = 0;
//         glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
//         glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
//         glutInitWindowPosition(3072 / 2 - WINDOW_WIDTH / 2, 1920 / 2 - WINDOW_HEIGHT / 2); 
//         glutCreateWindow("Screen Saver");
//         glutKeyboardFunc(keyInput);
//         // while (true) {
//             glutDisplayFunc(drawScreenSaver); 
//             glutReshapeFunc(resize);
//         // }
//         glewExperimental = GL_TRUE;
//         glewInit();

//         glClearColor(
//             COLOR2FLOAT(0),
//             COLOR2FLOAT(12),
//             COLOR2FLOAT(13),
//             COLOR2FLOAT(255)
//         );
//         glutMainLoop(); 
//     }
//     // int main(int argc, char **argv) {
//     //     glutInit(&argc, argv);
//     //     RKScreenSaver ss;
//     // }