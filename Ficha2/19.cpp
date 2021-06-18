#include <iostream>

class SpreadsheetCell{ // an "abstract class"
    public:
        SpreadsheetCell() { };
        virtual ~SpreadsheetCell() { };
        virtual void set(const std::string& inString) = 0;
        virtual std::string getString() const = 0;
}; 

class SpreadsheetCellString: public SpreadsheetCell{
    public:
        SpreadsheetCellString() { };
        ~SpreadsheetCellString() { };
        void set(const std::string& inString){
            content = inString;
        }
        std::string getString() const{
            return content;
        }
    private:
        std::string content;
};

class SpreadsheetCellDouble: public SpreadsheetCell{
    public:
        SpreadsheetCellDouble() { };
        ~SpreadsheetCellDouble() { };
        void set(const std::string& inString){
            content = stod(inString);
        }
        void set(const double& inDouble){
            content = inDouble;
        }
        double getDouble() const{
            return content;
        }
    private:
        double content;
};