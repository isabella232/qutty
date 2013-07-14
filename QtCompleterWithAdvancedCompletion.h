#ifndef QTCOMPLETERWITHADVANCEDCOMPLETION_H
#define QTCOMPLETERWITHADVANCEDCOMPLETION_H

#include <QCompleter>
#include <QListView>
#include <QStringListModel>
#include <QLineEdit>
#include <QComboBox>

class QtCompleterWithAdvancedCompletion : public QObject
{
    Q_OBJECT

public:
    enum FilterMode {
        StartsWith,
        Contains,
        ContainsWord
    };

private:
    QWidget *w;
    QListView *popuplist;
    QStringList completions;
    QStringListModel *model;
    int maxVisibleItems;
    int noItemsShown;
    FilterMode filterMode;

    void init();

public:
    explicit QtCompleterWithAdvancedCompletion(QLineEdit *le);
    explicit QtCompleterWithAdvancedCompletion(QComboBox *cb);

    void setModel(QStringList &completions);
    void setMaxVisibleItems(int maxItems) { maxVisibleItems = maxItems; }
    void setFilterMode(FilterMode mode) { filterMode = mode; }

protected:
    bool eventFilter(QObject *o, QEvent *e);

signals:
    void activated(const QString & text);

private slots:
    void slot_completerComplete(QModelIndex index);

public slots:
    void completionSearchString(QString str);

};

#endif // QTCOMPLETERWITHADVANCEDCOMPLETION_H
