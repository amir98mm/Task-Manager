#include <string>
using std::string;


class Task {
public:
    enum class Status {
        ToDo,
        InProgress,
        Done,
        Unkown
    };

    Task() = default;
    Task(const std::string& name, const std::string& description, int priority, const std::string& dueDate, Status status);

    const std::string& getName() const;
    const std::string& getDescription() const;
    int getPriority() const;
    const std::string& getDueDate() const;
    Status getStatus() const;

    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setPriority(int priority);
    void setDueDate(const std::string& dueDate);
    void setStatus(Status status);

private:
    std::string name;
    std::string description;
    int priority;
    std::string dueDate;
    Status status;
};
