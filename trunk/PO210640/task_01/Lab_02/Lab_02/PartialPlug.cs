using System;
using System.Windows;

namespace Lab_02;

public partial class MainWindow : Window
{
    private partial void AcceptButton_Click(object sender, RoutedEventArgs e);
}

public partial class App : Application
{
    public Guid Guid { get; init; } = Guid.NewGuid();
    public partial Guid GetGuid();
}
