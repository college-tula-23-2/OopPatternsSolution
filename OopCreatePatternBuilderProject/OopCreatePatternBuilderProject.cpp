#include <iostream>
#include <map>

enum class QueryItem
{
    Table,
    Where,
    Join,
    OrderBy,
    Select
};

class Query
{
    std::map<QueryItem, std::string> queryItems;
public:
    void AddItem(QueryItem item, std::string itemString)
    {
        queryItems.insert(std::make_pair(item, itemString));
    }

    void Print()
    {
        std::cout << "SELECT " << queryItems[QueryItem::Select] << "\n";
        std::cout << "\t FROM " << queryItems[QueryItem::Table] << "\n";

        if(queryItems.contains(QueryItem::Where))
            std::cout << "\t WHERE " << queryItems[QueryItem::Where] << "\n";

        if (queryItems.contains(QueryItem::Join))
            std::cout << "\t JOIN " << queryItems[QueryItem::Join] << "\n";

        if (queryItems.contains(QueryItem::OrderBy))
            std::cout << "\t ORDER BY " << queryItems[QueryItem::OrderBy] << "\n";
    }
};

class QueryBuilder
{
    Query* query;
public:
    QueryBuilder()
    {
        query = new Query();
    }

    QueryBuilder* Reset()
    {
        query = new Query();
        return this;
    }

    QueryBuilder* AddTable(std::string table)
    {
        query->AddItem(QueryItem::Table, table);
        return this;
    }

    QueryBuilder* AddWhere(std::string whereString)
    {
        query->AddItem(QueryItem::Where, whereString);
        return this;
    }

    QueryBuilder* AddJoin(std::string joinTable, std::string joinExpression)
    {
        query->AddItem(QueryItem::Join, joinTable + " ON " + joinExpression);
        return this;
    }

    QueryBuilder* AddOrderBy(std::string fieldOrder, bool asc = true)
    {
        query->AddItem(QueryItem::OrderBy, fieldOrder + ( asc ? " ASC" : " DESC"));
        return this;
    }

    QueryBuilder* AddSelect(std::string fields)
    {
        query->AddItem(QueryItem::Select, fields);
        return this;
    }

    Query* Create()
    {
        return query;
    }
};

int main()
{
    QueryBuilder* builder = new QueryBuilder();
    Query* query = builder->AddTable("Students")
                        ->AddSelect("*")
                        ->AddOrderBy("last_name")
                        ->Create();

    query->Print();

    query = builder->Reset() 
        ->AddOrderBy("c.title", false)
        ->AddJoin("Cities AS c", "c.id = af.city_id")
        ->AddSelect("af.title, af.date, c.title")
        ->AddTable("Airflights AS af")
        ->Create();

    query->Print();

}
