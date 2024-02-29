from django import forms 

class RegForm(forms.Form): 
    title = forms.CharField() 
    description = forms.CharField() 
    views = forms.IntegerField() 
    available = forms.BooleanField()

class CommentForm(forms.Form): 
    name = forms.CharField() 
    url = forms.URLField() 
    comment = forms.CharField(widget=forms.Textarea)