//Nikole Florence
//SWDV-460
//11-12-24

//parser and tree called from libmxl to parse xml files and create a tree from the nodes
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

//parse_xml function created
void parse_xml(const char *xmlFile){
    xmlDocPtr doc = cmlReadFile(xmlFile, NULL, 0);

//if the doc isnt able to be read, an error message is shown
    if(doc == NULL){
        fprintf(stderr, "Unable to parse XML file: %s\n", xmlFile);
        return;
    }

    xmlNodePtr root = xmlDocGetRootElement(doc);

//for loop is used to loop through the nodes from the root
//the element and its contents are then printed
    for(xmlNodePtr node = root->children; node; node = node->next){
        if(node->type == XML_ELEMENT_NODE){
            printf("Element: %s\n", node->name);

            xmlChar *content = xmlNodeGetContent(node);
            if(content){
                printf("Text: %s\n", content);
                xmlFree(content);
            }
        }
    }

//doc and parser are freed
    xmlFreeDoc(doc);
    xmlCleanupParser();
}

//main function is created which keeps track of the usage and then called the parse function
    int main(int argc, char *argv[]){
        if(argc != 2){
            fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
            return 1;
    }

    const char *xmlFile = argv[1];
    parse_xml(xmlFile);
    return 0;
}