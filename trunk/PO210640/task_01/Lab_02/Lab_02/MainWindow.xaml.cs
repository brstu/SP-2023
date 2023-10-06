using System;
using System.Windows;

namespace Lab_02
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            _guid = Guid.NewGuid();
            (Application.Current as App).Guid = Guid.NewGuid(); 
        }

        private void AcceptButton_Click(object sender, RoutedEventArgs e)
        {
            var random = new Random();
            var wished = random.Next(1, 10 + 1);

            var isOk = int.TryParse(GuessTextBox.Text, out int guessed);
            if (!isOk)
            {
                MessageBox.Show(
                        "Enter integer value",
                        "Error",
                        MessageBoxButton.OK,
                        MessageBoxImage.Error,
                        MessageBoxResult.None,
                        MessageBoxOptions.ServiceNotification);

                return;
            }

            if (guessed == wished)
            {
                MessageBox.Show(
                        $"You are right, my number is {wished}",
                        "Success",
                        MessageBoxButton.OK,
                        MessageBoxImage.Information,
                        MessageBoxResult.None,
                        MessageBoxOptions.ServiceNotification);

                return;
            }

            MessageBox.Show(
                        $"You are wrong, my number was {wished}. Try again :)",
                        "Failed",
                        MessageBoxButton.OK,
                        MessageBoxImage.Warning,
                        MessageBoxResult.None,
                        MessageBoxOptions.ServiceNotification);
        }
    }
}
