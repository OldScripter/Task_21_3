#include <iostream>
#include <cmath>

struct Vector
{
    float x;
    float y;

    /*
     * Add vector a to base vector.
     */
    Vector add(Vector& a) {
        Vector result{x + a.x, y + a.y};
        return result;
    }

    /*
     * Subtract vector a from base vector.
     */
    Vector subtract(Vector& a)
    {
        Vector result{x - a.x, y - a.y};
        return result;
    }

    /*
     * Scale base vector on factor f.
     */
    void scale(float f)
    {
        x *= f;
        y *= f;
    }

    /*
     * Get base vector length.
     */
    float length() const
    {
        return std::sqrt(x * x + y * y);
    }

    /*
     * Normalize the base vector.
     */
    void normalize()
    {
        float l = length();
        x *= 1 / l;
        y *= 1 / l;
    }

    /*
     * Print base vector coords and length.
     */
    void print(std::string tag)
    {
        std::cout << tag << ":\n";
        std::printf("x = %.2f, y = %.2f \n", x, y);
        std::printf("l = %.2f \n", length());
        std::cout << "-----------------------------------------\n";
    }

};

/*
 * Get command from keyboard input.
 */
std::string getCommandFromKeyboard()
{
    std::cout << "Please enter the command:\n";
    std::cout << "\t + \t : add vector to base vector;\n";
    std::cout << "\t - \t : subtract vector from base vector;\n";
    std::cout << "\t * \t : scale base vector;\n";
    std::cout << "\t l \t : get base vector length;\n";
    std::cout << "\t n \t : normalize base vector;\n";
    std::cout << "\t e \t : to exit;\n";
    std::string command;
    std::getline(std::cin, command);
    std::cin.clear();
    std::cout << "Your command is: " << command << "\n";
    return  command;
}

/*
 * Get float value from keyboard input.
 */
float getFloatFromKeyboard(std::string message)
{
    std::cout << message << ":\n";
    std::string buffer;
    getline(std::cin, buffer);
    try
    {
        float f = std::stof(buffer);
        return f;
    } catch (std::invalid_argument& exc)
    {
        std::cerr << "Transition error (" << buffer << ") to float.\n";
        std::cerr << "Returns zero as a result.\n";
        return 0;
    }
}

/*
 * Set the vector x and y via console and keyboard input of coords.
 */
void setVector(Vector& v, std::string vectorTag)
{
    v.x = getFloatFromKeyboard("Please enter the x value for the " + vectorTag);
    v.y = getFloatFromKeyboard("Please enter the y value for the " + vectorTag);
}

int main() {

    Vector baseVector {0, 0};
    do
    {
        if (baseVector.x == .0f && baseVector.y == .0f)
        {
            setVector(baseVector, "base vector");
            baseVector.print("base vector");
        }

        std::string command = getCommandFromKeyboard();

        if (command == "+")
        {
            std::cout << "Adding...\n";
            Vector targetVector {0, 0};
            setVector(targetVector, "vector to be added");
            baseVector = baseVector.add(targetVector);
            baseVector.print("result vector");
        }
        else if (command == "-")
        {
            std::cout << "Subtracting...\n";
            Vector targetVector {0, 0};
            setVector(targetVector, "vector to be subtracted");
            baseVector = baseVector.subtract(targetVector);
            baseVector.print("result vector");
        }
        else if (command == "l")
        {
            std::printf("The length of base vector: %.2f \n", baseVector.length());
        }
        else if (command == "*")
        {
            std::cout << "Scaling...\n";
            float factor = getFloatFromKeyboard("Enter the scaling factor");
            baseVector.scale(factor);
            baseVector.print("base vector after scaling");
        }
        else if (command == "n")
        {
            std::cout << "Normalizing...\n";
            baseVector.normalize();
            baseVector.print("normalized base vector");
        }
        else if (command == "e")
        {
            std::cout << "Exit...\n";
            break;
        }
        else
        {
            std::cerr << "Bad command. Try again.\n";
        }

    } while(true);

    return 0;
}
